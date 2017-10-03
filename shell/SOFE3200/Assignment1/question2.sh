file="sampling.txt" # File to be written into

while : # Infinite loop
do
    now=$(date +"%T") # Get the current time
    echo "Current time is: $now" >> $file # Write time into the file
    echo "Wrote time to $file Press [CTRL+C] to stop.."
    sleep 5 # Delay thread for five seconds
done
