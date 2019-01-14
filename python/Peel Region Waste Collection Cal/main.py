# from ics import Calendar, Event

# c = Calendar()
# e = Event()
# e.name = "My cool event"
# e.begin = '20190114 00:00:00'
# c.events.add(e)

# with open('my.ics', 'w') as my_file:
#     my_file.writelines(c)

file_data = list() # Raw file data
dates_dictionary = dict() # Dictionary with Dates and number of entries correspinding to each day

def parse_file(fname):
    with open(fname) as f:
        content = f.readlines()
    content = [x.strip() for x in content] # Remove whitespace and newline
    content = filter(None, content) # remove empty items
    return content

def main():
    file_data = parse_file("raw_data.txt")
    # If the last char of a line is a number it is date
    for x in file_data :
        x_code = unicode(x, 'utf-8')
        if x_code[-1:].isnumeric():
            dates_dictionary.update({x:0})

    print dates_dictionary


if __name__ == "__main__":
    main()
