#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
 
int main(void)
{
	puts("---> PwnKit-Hunter <---\n");
	puts("[*] DISCLAIMER: This tool is only valid on Debian, Ubuntu, and their variants.");
	
    pid_t pid = fork();
     
    if ( pid == 0 ) {
       /* The pathname of the file passed to execl()
          is not defined   */
        puts("[*] pkexec usage may appear, if so, you may ignore it.\n");
        execve("/usr/bin/pkexec", (char*[]){NULL}, NULL);
    }
 
    else {
        int status;
     
        waitpid(pid, &status, 0);
    
        if ( WIFEXITED(status) )
        {
            int exit_status = WEXITSTATUS(status);

            puts("\n\n");

            // The current version is patched.
            if (exit_status == 1) {
            	puts("[+] Your policykit-1 package is up-to-date. Keep updating and being secured.\n");
            }
            else {
            	puts("[-] Your policykit-1 package is vulnerable.\n[*]Use: 'apt install policykit-1' to update to the patched version.\n");
            }
        }
    }
    
    
    return 0;
    
}
