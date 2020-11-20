import time
import pyautogui

while True:
  localtime = time.localtime()
  result = time.strftime("Key pressed at %I:%M:%S %p", localtime)
  print(result)
  pyautogui.press('f14') # brightness down
  pyautogui.press('f15') # brightness up
  time.sleep(3*60)
