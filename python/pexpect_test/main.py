# This connects to the openbsd ftp site and
# downloads the recursive directory listing.
import secret
import pexpect
import sys

child = pexpect.spawn('bash')
child.logfile = sys.stdout
child.expect('\$')
child.sendline('ssh '+secret.machine)
child.expect('password:')
child.sendline(secret.password)
child.expect('\$')
child.sendline('passwd')
child.expect('password:') # Expect old passwd line
child.sendline(secret.password)
child.expect('password:') # Expect new passwd line
child.sendline(secret.new_password)
child.expect('password again:') # Expect new passwd again line
child.sendline(secret.new_password)
child.expect('\$')
child.sendline('ls -l')
child.expect('\$')
child.close()
