import csv
import random
import sys

rooms = ["Living Room",
         "Bedroom",
         "Kitchen", "Garage",
         "Library",
         "Attic",
         "Dining Room"]

def generate_temperature():
    return round(random.uniform(-1, 35), 1)

def populate_csv(filename, num_entries):
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Temperature','Room'])

        for _ in range(num_entries):
            temperature = generate_temperature()
            room = random.choice(rooms)
            writer.writerow([temperature, room])



output_file = sys.argv[1]
rows = int(sys.argv[2])
populate_csv(output_file, rows)
