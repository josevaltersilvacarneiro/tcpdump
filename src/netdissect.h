
typedef struct netdissect_options netdissect_options;

struct netdissect_options {
	int ndo_bflag;		// print 4 byte ASes in ASDOT notation
	int ndo_eflag;		// print ethernet header
	int ndo_fflag;		// don't translate "foreign" IP address
	int ndo_Kflag;		// don't check IP, TCP or UDP checksums
	int ndo_nflag;		// leave addresses as numbers
	int ndo_Nfalg;		// remove domains from printed host names
	int ndo_qflag;		// quick (shorter) output
	int ndo_Sflag;		// print raw TCP sequence numbers
	int ndo_tflag;		// print packet arrival time
	int ndo_uflag;		// print undercoded NFS handles
	int ndo_vflag;		// verbosity level
	int ndo_xflag;		// print packet in hex
	int ndo_Xflag;		// print packet in hex/ASCII
	int ndo_Aflag;		/* print packet only in ASCII observing TAB,
				 * LF, CR, and SPACE as graphical chars
				 */
	int ndo_Hflag;		// dissect 802.11s draft mesh standard
	const char *ndo_protocol; // protocol
	jmp_buf ndo_early_end;	// jmp_buf for setjmp()/longjmp()
	void *ndo_last_mem_p;	// pointer to the last allocate memory chuck
	int ndo_packet_number;	// print a packet number in the beginning of file
	int ndo_print_sampling;	// print every Nth packet
	int ndo_suppress_default_print; // don't use default_print() for unknown packet types
	int ndo_tstamp_precision;	// Requested time stamp precision
	const char *program_name;	// Name of program using the library

};
