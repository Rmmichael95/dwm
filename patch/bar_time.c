int
width_stime(Bar *bar, BarArg *a)
{
	return TEXTW(" xxx xx:xx ");
}

int
draw_stime(Bar *bar, BarArg *a)
{
    FILE *fp;
	char path[PATH_MAX];

	/* Open command for reading */
	fp = popen("/home/ryanm/.local/bin/statusbar/sb-clock", "r");
	if (fp == NULL) {
		printf("Failed to run command\n" );
	}

	while (fgets(path, PATH_MAX, fp) != NULL) {
	    pclose(fp);
        return drw_text(drw, a->x, a->y, a->w, a->h, lrpad / 2, path, 0, False);
	}
	pclose(fp);
    return drw_text(drw, a->x, a->y, a->w, a->h, lrpad / 2, path, 0, False);

}

int
click_stime(Bar *bar, Arg *arg, BarArg *a)
{
	return ClkTime;
}

