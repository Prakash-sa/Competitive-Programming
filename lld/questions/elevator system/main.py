import random

from ElevatorSystem import ElevatorSystem
from Direction import Direction

def run_call(system, floor, dir):
    print(f"Passenger calls lift on floor {floor} ({dir.name})")
    nearest = system.get_nearest_idle_car(floor)
    if nearest is None:
        print("No idle elevator available right now.")
        return
    print(f"→ Nearest elevator is {nearest.get_id()+1} at floor {nearest.get_current_floor()}. Lift going {dir.name}.")
    system.call_elevator(floor, dir)
    system.dispatcher()
    print("\n[Status after dispatch]")
    system.monitoring()
    print('-' * 100)

def main():
    num_floors = 13
    num_cars = 3
    num_panels = 1   # Number of HallPanels per floor
    num_displays = 3 # Number of Displays per floor

    system = ElevatorSystem.get_instance(num_floors, num_cars, num_panels, num_displays)

    # SCENARIO 1
    print("=== Scenario 1: Elevator 3 in maintenance, passenger calls elevator from floor 7 ===\n")
    system.monitoring()
    print()

    car3 = system.get_cars()[2]
    car3.enter_maintenance()
    print()
    system.monitoring()
    print()

    run_call(system, 7, Direction.UP)

    car3.exit_maintenance()
    print("\n--- Resetting maintenance for all elevators ---\n")
    system.monitoring()
    print()

    print("=== Scenario 2: Random positions, passenger calls elevator from ground (0) to top (12) ===")

    for car in system.get_cars():
        random_floor = random.randint(0, num_floors - 1)
        print(f"\n== Setting random position for Elevator {car.get_id()+1} ==")
        print(f"→ Teleporting Elevator {car.get_id()+1} to floor {random_floor}")
        car.register_request(random_floor)
        car.move()

    print("\nElevator positions after random repositioning:")
    for car in system.get_cars():
        print(f"Elevator {car.get_id()+1} ► Floor: {car.get_current_floor()} | State: {car.get_state().name}")
    print()

    run_call(system, 0, Direction.UP)

if __name__ == "__main__":
    main()
