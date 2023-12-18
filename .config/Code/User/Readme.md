### Add following lines on 

 - .vscode-oss/argv.json`enter code here`
			
		// Allows to disable crash reporting.
		// Should restart the app if the value is changed.
		"enable-crash-reporter": true,
		"password-store": "gnome",	
		// Unique id used for correlating crash reports sent from this instance.
		// Do not edit this value.
		"crash-reporter-id": "4805a1ab-42bd-4ad7-befc-3c4c84ac6a81",
		"enable-proposed-api": ["github.copilot"]

Added
 1. ["enable-proposed-api": ["github.copilot"] ] 
 2. [ "password-store": "gnome"] 



**$ cat /etc/pam.d/login**

			#%PAM-1.0
			auth       required     pam_securetty.so
			auth       requisite    pam_nologin.so
			auth       include      system-local-login
	[+]		auth       optional     pam_gnome_keyring.so
			account    include      system-local-login
			session    include      system-local-login
			password   include      system-local-login
	[+]		session    optional     pam_gnome_keyring.so auto_start


**Added** [+] above . auto start gnome_keyring.so on login 


**Make sure :** 

 1. You have installed gnome-keyring
 2. You have VSIX MANAGER extension on code-oss 
	
	After installing VSIX Manager , 
		
		Download .vsix file of githubcopilot extension 
		
	[https://marketplace.visualstudio.com/items?itemName=GitHub.copilot]
		
		Now install .vsix file navigating it using Ctrl+shift+P ,
		command :  **Install From VSIX**   then select the .vsix file.

** Upper thing all applies to vscode-oss and codium but for vscode it dosen't 

## Extensions compulasory are: 
* which-key 
* neovim 

-- Additionals :
    C/C++ Clangd 
    Live Server 
    Path Intellisense 
    Prettier-Code 
    pylance -> uses pyright and recommended for vscode with optimization
    pyhton Intellisense-> with lsp as Pylance 
    Github -copilot 
