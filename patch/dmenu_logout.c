void
dmenu_logout(const Arg *arg)
{
	FILE *fp;
	char path[PATH_MAX];

	/* Open command for reading */
	fp = popen("echo 'Yes' | dmenu -p 'Would you like to logout?'", "r");
	if (fp == NULL) {
		printf("Failed to run command\n" );
	}

	while (fgets(path, PATH_MAX, fp) != NULL) {
		if (strcmp(path, "Yes")) {
			pclose(fp);
			quit(0);
		}
	}
	pclose(fp);
}


