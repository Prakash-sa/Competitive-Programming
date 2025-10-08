from enum import Enum

class BookFormat(Enum):
    HARDCOVER=1
    PAPERCOVER=2
    AUDIOBOOK=3
    EBOOK=4
    NEWSPAPER=5
    MAGAZINE=6
    JOURNAL=7

class BookStatus(Enum):
    AVAILABLE=1
    RESERVED=2
