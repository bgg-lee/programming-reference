class Country:
    def __init__(self, name, population, area):

        # write your code below
        self.name = name
        self.population = population
        self.area = area


    
    def is_larger(self, other):

        # write your code below
        if self.area > other.area:
            return True
        else:
            return False

    
    def population_density(self):

        # write your code below
        return self.population / self.area