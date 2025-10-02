from enum import Enum

class Direction(Enum):
    UP=1
    DOWN=2
    IDLE=3

class ElevatorState(Enum):
    IDLE=1
    UP=2
    DOWN=3
    MAINTENANCE=4

class DoorState(Enum):
    OPEN=1
    CLOSED=2
