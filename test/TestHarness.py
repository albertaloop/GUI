import time
import importlib
from argparse import ArgumentParser


command_socket = None
telemetry_socket = None
wait_time = 10

command_ip = "127.0.0.1"
telemetry_ip = "127.0.0.1"
command_port = 3000
telemetry_port = 4000


def setup_sockets():
    global command_socket, telemetry_socket
    command_socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    telemetry_socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    command_socket.bind((command_ip, command_port))

def load_test_module(module_name):
    return importlib.import_module(module_name)



def run_test(test_case_module):
    # Load and initialize the test case
    test_case = test_case_module.TestCase()
    test_case.setup()

    try:
        start_time = time.time()
        while True:

            # Check for incoming commands
            data = udp_socket.recvfrom(1024)

            # Process command using the test case's logic
            test_case.process_command()

            # Check if it's time to send the next telemetry packet
            end_time = time.time()
            if end_time - start_time >= wait_time:
                packet = test_case.get_next_telemetry_packet()
                if packet:
                    telemetry_socket.sendto(packet, server_address)
                start_time = time.time()

    finally:
        # Ensure test resources are cleaned up properly
        test_case.teardown()


if __name__ == "__main__":

    # Create the parser
    parser = argparse.ArgumentParser(description="Mock the pod electronics")

    parser.add_argument('module_name', type=str, help='The name of the module')

    args = parser.parse_args()

    print(f"Module name: {args.module_name}")

    setup_sockets()

    test_case_module = load_test_module(args.module_name)

    run_test(test_case_module)