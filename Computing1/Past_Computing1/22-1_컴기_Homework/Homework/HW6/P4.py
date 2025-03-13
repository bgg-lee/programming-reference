class Calculator:
    def __init__(self):
        #write your code below
        self.now = 0
        self.calc = []
        
    def digit(self,num):
        #write your code below
        if self.now == 0 and num == 0 : # 시작 0, 버튼 0 -> 0 
            self.now = 0
        elif  self.now == 0 and num != 0 : # 시작 0, 버튼 숫자 -> 숫자
            self.now = num                               
        elif  self.now != 0 and num == 0 : # 시작 숫자, 버튼 0 -> 숫자 + 0
            self.now = int(str(self.now) + str(num))                    
        else:                       # 시작 숫자, 버튼 숫자 -> 숫자 + 숫자
            self.now = int(str(self.now) + str(num))

    
    def plus(self):
        #write your code below

        if self.now != 0:
            self.calc.append(self.now)
            self.calc.append('plus')
            self.now = 0
        else:
            if self.calc == []:
                pass
            elif type(self.calc[-1]) != int:
                del self.calc[-1]
            self.calc.append('plus')
            self.now = 0
    

    def minus(self):
        #write your code below
        if self.now != 0:
            self.calc.append(self.now)  
            self.calc.append('minus')
            self.now = 0
        else:
            if self.calc == []:
                pass
            elif type(self.calc[-1]) != int:
                del self.calc[-1]
            self.calc.append('minus')
            self.now = 0

    def clear(self):
        #write your code below
        self.now = 0
        self.calc = []

    def equal(self):
        #write your code below
        ans = 0
        self.calc.append(self.now)
        self.calc.append('equal')
        for i in range(len(self.calc)):
            if type(self.calc[i]) == int:
                ans += self.calc[i]
            elif self.calc[i] == 'plus':
                pass
            elif self.calc[i] == 'minus' :
                self.calc[i+1] = - (self.calc[i+1])
            elif self.calc[i] == 'equal':
                return ans