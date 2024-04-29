# Design rock paper scissor game using python
# snake game using python
# value converter using python (cm to inch, inch to cm, km to mile, mile to km, kg to pound, pound to kg)

import random
import turtle
import time
    
def rock_paper_scissor():
    values = {
        1: "Rock",
        2: "Paper",
        3: "Scissor" }
   
    print("Rock Paper Scissor Game")
    print("1. Rock")
    print("2. Paper")
    print("3. Scissor")
    choice = int(input("Enter your choice: "))
    if choice in values:
        print(f"Your choice: {values[choice]}")
        computer_choice = random.randint(1, 3)
        print(f"Computer's choice: {values[computer_choice]}")
        if choice == computer_choice:
            print("It's a tie")
        elif choice == 1 and computer_choice == 3:
            print("You win")
        elif choice == 2 and computer_choice == 1:
            print("You win")
        elif choice == 3 and computer_choice == 2:
            print("You win")
        else:
            print("Computer wins")
    else:
        print("Invalid choice")
    
        
def snake_game():
    delay = 0.1
    score = 0
    high_score = 0

    # Set up the screen
    wn = turtle.Screen()
    wn.title("Snake Game")
    wn.bgcolor("black")
    wn.setup(width=600, height=600)
    wn.tracer(0)

    # Snake head
    head = turtle.Turtle()
    head.speed(0)
    head.shape("square")
    head.color("white")
    head.penup()
    head.goto(0, 0)
    head.direction = "stop"

    # Snake food
    food = turtle.Turtle()
    food.speed(0)
    food.shape("circle")
    food.color("red")
    food.penup()
    food.goto(0, 100)

    segments = []

    # Pen
    pen = turtle.Turtle()
    pen.speed(0)
    pen.shape("square")
    pen.color("white")
    pen.penup()
    pen.hideturtle()
    pen.goto(0, 260)
    pen.write("Score: 0 High Score: 0", align="center", font=("Courier", 24, "normal"))

    # Functions
    def go_up():
        if head.direction != "down":
            head.direction = "up"

    def go_down():
        if head.direction != "up":
            head.direction = "down"

    def go_left():
        if head.direction != "right":
            head.direction = "left"

    def go_right():
        if head.direction != "left":
            head.direction = "right"

    def move():
        if head.direction == "up":
            y = head.ycor()
            head.sety(y + 20)

        if head.direction == "down":
            y = head.ycor()
            head.sety(y - 20)

        if head.direction == "left":
            x = head.xcor()
            head.setx(x - 20)

        if head.direction == "right":
            x = head.xcor()
            head.setx(x + 20)

    # Keyboard bindings
    wn.listen()
    wn.onkeypress(go_up, "w")
    wn.onkeypress(go_down, "s")
    wn.onkeypress(go_left, "a")
    wn.onkeypress(go_right, "d")

    # Main game loop
    while True:
        wn.update()

        # Check for collision with the border
        if head.xcor() > 290 or head.xcor() < -290 or head.ycor() > 290 or head.ycor() < -290:
            time.sleep(1)
            head.goto(0, 0)
            head.direction = "stop"

            # Hide the segments
            for segment in segments:
                segment.goto(1000, 1000)

            # Clear the segments list
            segments.clear()

            # Reset the score
            score = 0

            # Reset the delay
            delay = 0.1

            pen.clear()
            pen.write("Score: {} High Score: {}".format(score, high_score), align="center",
                      font=("Courier", 24, "normal"))

        # Check for collision with the food
        if head.distance(food) < 20:
            # Move the food to a random spot
            x = random.randint(-290, 290)
            y = random.randint(-290, 290)
            food.goto(x, y)

            # Add a segment
            new_segment = turtle.Turtle()
            new_segment.speed(0)
            new_segment.shape("square")
            new_segment.color("grey")
            new_segment.penup()
            segments.append(new_segment)

            # Shorten the delay
            delay -= 0.001

            # Increase the score
            score += 10

            if score > high_score:
                high_score = score

            pen.clear()
            pen.write("Score: {} High Score: {}".format(score, high_score), align="center",
                      font=("Courier", 24, "normal"))

        # Move the end segments first in reverse order
        for index in range(len(segments) - 1, 0, -1):
            x = segments[index - 1].xcor()
            y = segments[index - 1].ycor()
            segments[index].goto(x, y)

        # Move segment 0 to where the head is
        if len(segments) > 0:
            x = head.xcor()
            y = head.ycor()
            segments[0].goto(x, y)

        move()

        # Check for head collision with the body segments
        for segment in segments:
            if segment.distance(head) < 20:
                time.sleep(1)
                head.goto(0, 0)
                head.direction = "stop"

                # Hide the segments
                for segment in segments:
                    segment.goto(1000, 1000)

                # Clear the segments list
                segments.clear()

                # Reset the score
                score = 0

                # Reset the delay
                delay = 0.1

                pen.clear()
                pen.write("Score: {} High Score: {}".format(score, high_score), align="center",
                          font=("Courier", 24, "normal"))

        time.sleep(delay)
        
        
def value_converter():
    print("Value Converter")
    print("1. cm to inch")
    print("2. inch to cm")
    print("3. km to mile")
    print("4. mile to km")
    print("5. kg to pound")
    print("6. pound to kg")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        cm = float(input("Enter the value in cm: "))
        inch = cm / 2.54
        print(f"{cm} cm is equal to {inch} inch")
    elif choice == 2:
        inch = float(input("Enter the value in inch: "))
        cm = inch * 2.54
        print(f"{inch} inch is equal to {cm} cm")
    elif choice == 3:
        km = float(input("Enter the value in km: "))
        mile = km / 1.60934
        print(f"{km} km is equal to {mile} mile")
    elif choice == 4:
        mile = float(input("Enter the value in mile: "))
        km = mile * 1.60934
        print(f"{mile} mile is equal to {km} km")
    elif choice == 5:
        kg = float(input("Enter the value in kg: "))
        pound = kg * 2.20462
        print(f"{kg} kg is equal to {pound} pound")
    elif choice == 6:
        pound = float(input("Enter the value in pound: "))
        kg = pound / 2.20462
        print(f"{pound} pound is equal to {kg} kg")
    else:
        print("Invalid choice")
        
        
def main():
    print("1. Rock Paper Scissor Game")
    print("2. Snake Game")
    print("3. Value Converter")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        rock_paper_scissor()
    elif choice == 2:
        snake_game()
    elif choice == 3:
        value_converter()
    else:
        print("Invalid choice")
        
if __name__ == "__main__":
    main()