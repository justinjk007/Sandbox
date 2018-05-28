#!/usr/bin/env python
# python 2

import ConfigParser

config_contents = ConfigParser.RawConfigParser()
config_contents.readfp(open("./config.cfg"))

dictionary1 = dict()  # Create empty dictionary
dictionary1["name"] = config_contents.get("Some Section name", "some_id")
dictionary1["number1"] = config_contents.get("Some Section name", "num1")
dictionary1["number2"] = config_contents.get("Some Section name", "num2")

print dictionary1
