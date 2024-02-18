class TestCaseInterface:
    def setup(self):
        """Set up test resources."""
        pass

    def process_command(self):
        """Return the next piece of simulated data."""
        pass

    def get_next_telemetry_packet(self):
        """Simulate command logic, possibly injecting errors."""
        pass

    def teardown(self):
        """Clean up test resources."""
        pass
