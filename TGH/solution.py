def min_steps_to_balance_food(n, current_food, desired_food):
    # Calculate the difference between current and desired food
    differences = [current_food[i] - desired_food[i] for i in range(n)]
    
    # Calculate the total positive and negative differences
    positive_diff = sum(d for d in differences if d > 0)
    negative_diff = -sum(d for d in differences if d < 0)
    
    # The minimum steps required is the maximum of positive and negative differences
    return max(positive_diff, negative_diff)

# Read input from inp.txt
with open('/h:/OLP/TGH/inp.txt', 'r') as file:
    n = int(file.readline().strip())
    current_food = list(map(int, file.readline().strip().split()))
    desired_food = list(map(int, file.readline().strip().split()))

# Calculate the minimum steps
result = min_steps_to_balance_food(n, current_food, desired_food)

# Write the result to out.txt
with open('/h:/OLP/TGH/out.txt', 'w') as file:
    file.write(str(result) + '\n')
