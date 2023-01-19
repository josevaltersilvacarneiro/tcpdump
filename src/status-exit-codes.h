#ifndef status_exit_codes_h
#define status_exit_codes_h

// S_ERR_ND_* are libnetdissect status

typedef enum {
	S_SUCCESS		= 0, // not a libnetdissect status
	S_ERR_HOST_PROGRAM	= 1, // not a libnetdissect status
	S_ERR_ND_NO_PRINTER	= 11,
	S_ERR_ND_MEM_ALLOC	= 12,
	S_ERR_ND_OPEN_FILE	= 13,
	S_ERR_ND_WRITE_FILE	= 14,
	S_ERR_ND_ESP_SECRET	= 15
} status_exit_codes_t;

#endif // status_exit_codes_h
