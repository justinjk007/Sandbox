# This connects to the openbsd ftp site and
# downloads the recursive directory listing.
import secret
import pexpect
import sys

child = pexpect.spawn('bash')
child.logfile = sys.stdout
child.expect('\$')
child.sendline('ssh '+secret.machine)
child.expect('password: ')
child.sendline(secret.password)
child.expect('\$')
child.close()
