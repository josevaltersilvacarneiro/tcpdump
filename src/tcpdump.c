#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pcap/pcap.h>
#include <setjmp.h>

#include "netdissect.h"

#define PATH_SEPARATOR '/'

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

char *program_name;

struct dump_info {
	char *WFileName;
	char *CurrentFileName;
	pcap_t *pd;
	pcap_dumper_t *pdd;
	netdissect_options *ndo;
#ifdef HAVE_CAPSICUM
	int dirfd;
#endif
};

int
main(int argc, char *argv[])
{
	int cnt, op, i;
	unsigned long localnet, netmask;
	char *cp, *infile, *cmdbuf, *device, *RFileName, *VFileName, *WFileName;
	char *endp;
	pcap_handler callback; // #include <pcap.pcap.h>
	int dlt;
	const char *dlt_name;
	struct bpf_program fcode;

	void *oldhandler(int); // Only linux

	struct dump_info dumpinfo;
	u_char *pcap_userdata;
	char ebuf[PCAP_ERRBUF_SIZE];
	char VFileLine[PATH_MAX + 1];
	const char *username = NULL;

	const char chroot_dir = NULL; // Only Linux

	char *ret = NULL;
	char *end;

#ifdef HAVE_PCAP_FINDALLDEVS
	pcap_if_t *devlist;
	long devnum;
#endif
	int status;
	FILE *VFile;
#ifdef HAVE_CAPSICUM
	cap_rights_t rights;
	int cansandbox;
#endif /* HAVE CAPSICUM */
	int Oflag = 1; // run filter code optimizer 
	int yflag_dlt = 1;
	const char *yflag_dlt_name = NULL;
	int print = 0;
	long Cflagmult;

	struct netdissect_options Ndo;
	struct netdissect_options *ndo = &Ndo;

	// Initialize the netdissect code
	if (nd_init(ebuf, sizeof(ebuf)) == -1)
		error("%s", ebuf);

	memset(ndo, 0, sizeof(*ndo));
	ndo_set_function_pointers(ndo);

	cnt = -1;
	device = NULL;
	infile = NULL;
	RFileName = NULL;
	VFileName = NULL;
	VFile = NULL;
	WFileName = NULL;
	dlt = -1;

	if ((cp = strrchr(argv[0], PATH_SEPARATOR)) != NULL)
		ndo->program_name = program_name = cp + 1;
	else
		ndo->program_name = program_name = argv[0];

	return 0;
}

static void NORETURN PRINTFLINE(1, 2)
error(FORMAT_STRING(const char *fmt), ...)
{
	va_list ap;

	(void) fprintf(stderr, "%s", program_name);

	va_start(ap, fmt);
	(void) vfprintf(stderr, fmt, ap);
	va_end(ap);

	if (*fmt) {
		fmt += strlen(fmt);

		if (fmt[-1] != '\n')
			(void) fputc('\n', sterr);
	}
	exit_tcpdump(S_ERR_HOST_PROGRAM);
	// NOT REACHED
}
