import numpy as np
import csv
import sys

class DataStream:
    self.data_points = []
    self.system = None
    self.name
    def __init__(self, system, name):
        self.system = system
        self.name = name

    def set_system(system):
        self.system = system

    def set_current_point(self, point):
        if len(self.data_points > 0):
            self.data_points[-1] = point

    def get_current_point(self):
        if len(self.data_points > 0):
            return data_points[-1]

class DataGenerator:
    def __init__(self, system, start_time=0):
        self.system = system
        self.current_time = start_time
        self.data_points = []





class Simulation:
    def __init__(self):
        self.data_streams = []
        self.events = []
        self.current_time = 0

    def add_data_stream(self, data_stream):
        self.data_streams.append(data_stream)

    def schedule_event(self, event):
        self.events.append(event)
        self.events.sort(key=lambda event: event.time)

    def run(self, end_time):
        while self.current_time < end_time:
            if self.events and self.events[0].time <= self.current_time:
                event = self.events.pop(0)
                event.execute()

            for stream in self.data_streams:
                stream.system.update(self.current_time + 1)
                self.shared_data
            self.current_time += 1

    def generate_data(self, end_time, time_step=1):
        times = np.arange(self.current_time, end_time, time_step)
        for stream in self.data_streams:
            stream.system.update(time_step)
        return self.data_points

    def save_to_csv(self, file_name):
        with open(file_name, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(['Time', 'State'])  # Header
            for stream in self.data_streams:
                for point in stream.data_points:
                    writer.writerow(point)


if __name__ == "main":

    if len(sys.argv) != 3:
        print("Usage: python script.py <input_file_path> <output_file_path>")
        sys.exit(1)

    input_file_path = sys.argv[1]
    output_file_path = sys.argv[2]


    # Setup simulation
    sim = Simulation()
    linear_system = LinearSystem(initial_state=0)
    data_stream = DataStreamGenerator(system=linear_system)
    sim.add_data_stream(data_stream)

    # Schedule an event to change system state
    event = Event(time=5, function=change_system_state, args=(linear_system, 10))
    sim.schedule_event(event)

    # Run the simulation
    sim.run(end_time=10)