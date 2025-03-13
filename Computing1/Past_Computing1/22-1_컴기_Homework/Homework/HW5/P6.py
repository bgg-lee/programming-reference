def P6(input_filename: str, out_filename: str): 
    ##### Write your Code Here #####
    with open(input_filename, 'r') as input, open(out_filename, 'w') as output:
        input_bef = input.read()
        input_af = input_bef.replace(" ",",")
        output.write(input_af)

    ##### End of your code #####