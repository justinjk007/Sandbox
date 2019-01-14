from datetime import datetime
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
description = list() # Store the description of events happening each day
YEAR = '2019'

def parse_file(fname):
    with open(fname) as f:
        content = f.readlines()
    content = [x.strip() for x in content] # Remove whitespace and newline
    content = filter(None, content) # remove empty items
    return content

def main():
    file_data = parse_file("raw_data.txt")

    # Parse data into Dates and events
    date = ''
    event_num = 0
    for x in file_data :
        # If the last char of a line is a number it is date
        x_code = unicode(x, 'utf-8')
        if x_code[-1:].isnumeric():
            date = x
            event_num = 0
            dates_dictionary.update({date:event_num})
        else:
            event_num += 1
            dates_dictionary.update({date:event_num})
            description.append(x) # This is a waste type, not a date
    # Convert dates into needed format
    # https://docs.python.org/2/library/datetime.html#strftime-and-strptime-behavior
    date = datetime.strptime('Monday, February 4'+' '+YEAR, '%A, %B %d %Y') # Strip date
    print date.strftime('%Y%m%d') # Format date from stripped date

    


if __name__ == "__main__":
    main()
