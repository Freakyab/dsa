import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Input, LSTM, Dense, Embedding
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

# Load data
file_path = '/content/datasetFrench.csv'
data = pd.read_csv(file_path)

# Sample a smaller subset of the data for training
sample_size = 7000  # Adjust the sample size as needed
data = data.sample(n=sample_size, random_state=42)

# Define start and end tokens
start_token = '<sos>'
end_token = '<eos>'

# Extract English and French sentences
input_texts = data['French'].tolist()
target_texts = [start_token + ' ' + text + ' ' + end_token for text in data['English'].tolist()]

# Tokenizing the texts
input_tokenizer = Tokenizer(filters='')
input_tokenizer.fit_on_texts(input_texts)
input_sequences = input_tokenizer.texts_to_sequences(input_texts)

target_tokenizer = Tokenizer(filters='')
target_tokenizer.fit_on_texts(target_texts)
target_sequences = target_tokenizer.texts_to_sequences(target_texts)

# Find maximum lengths
max_input_length = max(len(seq) for seq in input_sequences)
max_target_length = max(len(seq) for seq in target_sequences)

# Padding sequences
encoder_input_data = pad_sequences(input_sequences, maxlen=max_input_length, padding='post')
decoder_input_data = pad_sequences(target_sequences, maxlen=max_target_length, padding='post')

# Create decoder target data (one-hot encoded)
decoder_target_data = np.zeros((len(target_texts), max_target_length, len(target_tokenizer.word_index) + 1), dtype='float32')

for i, seq in enumerate(target_sequences):
    for t, word in enumerate(seq):
        if t > 0:
            decoder_target_data[i, t - 1, word] = 1.0

# Define the model
latent_dim = 256

# Encoder
encoder_inputs = Input(shape=(None,))
encoder_embedding = Embedding(input_dim=len(input_tokenizer.word_index) + 1, output_dim=latent_dim)(encoder_inputs)
encoder_lstm = LSTM(latent_dim, return_state=True)
encoder_outputs, state_h, state_c = encoder_lstm(encoder_embedding)
encoder_states = [state_h, state_c]

# Decoder
decoder_inputs = Input(shape=(None,))
decoder_embedding = Embedding(input_dim=len(target_tokenizer.word_index) + 1, output_dim=latent_dim)(decoder_inputs)
decoder_lstm = LSTM(latent_dim, return_sequences=True, return_state=True)
decoder_outputs, _, _ = decoder_lstm(decoder_embedding, initial_state=encoder_states)
decoder_dense = Dense(len(target_tokenizer.word_index) + 1, activation='softmax')
decoder_outputs = decoder_dense(decoder_outputs)

# Define the model
model = Model([encoder_inputs, decoder_inputs], decoder_outputs)

# Compile the model
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

# Train the model
model.fit([encoder_input_data, decoder_input_data], decoder_target_data,
          batch_size=64,
          epochs=1,  # Adjust the number of epochs as needed
          validation_split=0.2)

# Encoder inference model
encoder_model = Model(encoder_inputs, encoder_states)

# Decoder inference model
decoder_state_input_h = Input(shape=(latent_dim,))
decoder_state_input_c = Input(shape=(latent_dim,))
decoder_states_inputs = [decoder_state_input_h, decoder_state_input_c]

decoder_outputs, state_h, state_c = decoder_lstm(
    decoder_embedding, initial_state=decoder_states_inputs)
decoder_states = [state_h, state_c]
decoder_outputs = decoder_dense(decoder_outputs)

decoder_model = Model(
    [decoder_inputs] + decoder_states_inputs,
    [decoder_outputs] + decoder_states)

def decode_sequence(input_seq):
    # Encode the input as state vectors.
    states_value = encoder_model.predict(input_seq)

    # Generate empty target sequence of length 1.
    target_seq = np.zeros((1, 1))
    start_token_index = target_tokenizer.word_index.get(start_token)
    if start_token_index is None:
        raise ValueError(f"The start token '{start_token}' is not in the target_tokenizer word index.")
    target_seq[0, 0] = start_token_index

    # Sampling loop for a batch of sequences
    stop_condition = False
    decoded_sentence = ''
    while not stop_condition:
        output_tokens, h, c = decoder_model.predict([target_seq] + states_value)

        # Sample a token
        sampled_token_index = np.argmax(output_tokens[0, -1, :])
        sampled_word = target_tokenizer.index_word.get(sampled_token_index, '')
        if not sampled_word:
            break  # Exit if the sampled word is not in the vocabulary

        decoded_sentence += ' ' + sampled_word

        # Exit condition: either hit max length or find end token.
        if sampled_word == end_token or len(decoded_sentence) > max_target_length:
            stop_condition = True

        # Update the target sequence (of length 1).
        target_seq = np.zeros((1, 1))
        target_seq[0, 0] = sampled_token_index

        # Update states
        states_value = [h, c]

    return decoded_sentence.strip()

def translate_french_to_english(french_sentence):
    # Preprocess the input sentence
    input_seq = input_tokenizer.texts_to_sequences([french_sentence])
    input_seq = pad_sequences(input_seq, maxlen=max_input_length, padding='post')

    # Decode the input sentence
    decoded_sentence = decode_sequence(input_seq)
    return decoded_sentence


# Ask the user for input
french_input = input("Enter a French sentence to translate to English: ")
translated_sentence = translate_french_to_english(french_input)
print('French input:', french_input)
print('English translation:', translated_sentence)