from datetime import datetime
from ics import Calendar, Event
from collections import OrderedDict

file_data = list() # Raw file data
dates_dictionary = OrderedDict() # Dictionary with Dates and number of entries for each day
dates_dictionary_formatted = OrderedDict() # Same dictionary formatted dates
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
    for x, y in dates_dictionary.items():
        date = datetime.strptime(x+' '+YEAR, '%A, %B %d %Y') # Strip date
        formatted_date = date.strftime('%Y%m%d') # Format date from stripped date
        dates_dictionary_formatted.update({formatted_date:y})
    # Format data into ics file
    c = Calendar()
    description_for_the_day = '' 
    for x, y in dates_dictionary_formatted.items():
        e = Event()
        e.name = "Waste Collection day"
        for i in range(y):
            description_for_the_day += description.pop(0)
            description_for_the_day += ','
        description_for_the_day = description_for_the_day[:-1] # Remove the comma at the end
        print 'Date: '+x
        print 'Number of events: '+str(y)
        print description_for_the_day
        e.begin = x+' 00:00:00'
        e.end = x+' 12:00:00'
        e.make_all_day() # Make the event all day
        e.description = description_for_the_day
        c.events.add(e)
        description_for_the_day = '' # Reset this
        del e
    # Write data into ics file
    print('Creating ics file')
    with open('my.ics', 'w') as my_file:
        my_file.writelines(c)

if __name__ == "__main__":
    main()
