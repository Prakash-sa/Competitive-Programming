class Movie:
    def __init__(self, t="", y=-1, g=""):
        self.__title = t
        self.__year = y
        self.__genre = g

    def get_title(self):
        return self.__title

    def set_title(self, value):
        self.__title = value

    def get_year(self):
        return self.__year

    def set_year(self, value):
        self.__year = value

    def get_genre(self):
        return self.__genre

    def set_genre(self, value):
        self.__genre = value

    def print_details(self):
        print("Title:", self.get_title())
        print("Year:", self.get_year())
        print("Genre:", self.get_genre())

def main():
    movie = Movie("The Lion King", 1994, "Adventure")
    movie.print_details()

    print("---")
    movie.set_title("Forrest Gump")
    print("New title:", movie.get_title())

if __name__ == "__main__":
    main()
    