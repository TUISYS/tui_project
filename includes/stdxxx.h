#ifndef __STD_XXX_H__
#define __STD_XXX_H__

#include <stdarg.h>

#ifndef NULL
#define NULL    0
#endif

#ifndef bool
#define bool	int
#endif

#ifndef false
#define false	0
#endif

#ifndef true
#define true	1
#endif

typedef signed char		int8_t;
typedef short			int16_t;
typedef int				int32_t;

typedef unsigned char	uint8_t;
typedef unsigned short	uint16_t;
typedef unsigned int	uint32_t;
typedef unsigned int	size_t;

#define STD_FS_ATTR_READONLY      0x00000001
#define STD_FSYS_ATTR_READONLY    0x00000001
#define STD_FSYS_ATTR_HIDDEN      0x00000002
#define STD_FSYS_ATTR_SYSTEM      0x00000004
#define STD_FSYS_FAT_VOLUME_ID    0x00000008
#define STD_FSYS_ATTR_DIRECTORY   0x00000010
#define STD_FSYS_ATTR_ARCHIVE     0x00000020

typedef struct __STDDIR
{
	uint32_t   tmp;
}STD_DIR;

typedef struct __STDDIRENT
{
	uint32_t     d_ino;  
	uint32_t      fatdirattr;
	uint32_t     d_size;
	char      d_name[1024];
}STD_DIRENT;

extern void std_time_gmt(unsigned int *t);
extern int std_atoi(const char *s);
extern void  std_Sleep(size_t dly);
extern void * std_calloc(size_t _Count, size_t _Size);
extern void *std_malloc(size_t size);
extern void std_free(void *ptr);
extern void *std_realloc(void *ptr, size_t size);
extern int std_random(int max);
extern size_t std_strlen(const char  *pstr);
extern char *std_strcpy(char *pdest, const char *psrc);
extern char *std_strncpy(char *pdest, const char *psrc, size_t len_max);
extern char *std_strcat(char *pdest, const char *pstr_cat);
extern char *std_strncat(char *pdest, char *pstr_cat, size_t len_max);
extern int std_strcmp(const char *p1_str, const char *p2_str);
extern int std_stricmp(const char *p1_str, const char *p2_str);
extern int std_strncmp(const char *p1_str, const char *p2_str, size_t len_max);
extern int std_strnicmp(const char *p1_str, const char *p2_str, size_t len_max);
extern char *std_strchr(char *pstr, char srch_char);
extern char *std_strrchr(const char *s, int c);
extern char *std_strstr(char *pstr, char *psrch_str);
extern void *std_memset(void *pmem, int data_val, size_t size);
extern void *std_memcpy(void *pdest, const void *psrc, size_t size);
extern int std_memcmp(const void *cs, const void *ct, size_t count);
extern char *std_strdup (const char *pstr);
extern size_t std_strcspn(const char *s, const char *reject);
extern void *std_memmove(void *dest, const void *src, size_t count);
extern char * std_strtok(char *s, const char *delim);


extern int std_vsnprintf(char *buffer, size_t size, const char *format, va_list arg);
extern int std_vscnprintf(char *buffer, size_t size, const char *format, va_list args);
extern int std_snprintf(char *buffer, size_t size, const char *format, ...);
extern int std_scnprintf(char *buffer, size_t size, const char *format, ...);
extern int std_vsprintf(char *buffer, const char *format, va_list args);
extern int std_sprintf(char *buffer, const char *format, ...);

extern int std_printf(const char *format, ...);



extern char std_tolower(char c);
extern double std_pow(double x, double y);
extern double std_fabs(double a);
extern double std_floor( double arg );

extern void std_bzero(void *s1, unsigned n);
extern int std_assert(uint32_t a, char* file, int lines);
extern uint32_t std_htonl(uint32_t h);
extern uint32_t std_ntohl(uint32_t n);
extern uint16_t std_htons(uint16_t h);
extern uint16_t std_ntohs(uint16_t n);


typedef uint32_t FILE;
#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

extern FILE * std_fopen(const char * _Filename, const char * _Mode);
extern int std_fseek( FILE * _File,  long _Offset,  int _Origin);
extern long std_ftell( FILE * _File);
extern size_t std_fread(void * _DstBuf,  size_t _ElementSize,  size_t _Count,  FILE * _File);
extern size_t std_fwrite(const void* _Str, size_t _Size, size_t _Count,  FILE * _File);
extern int std_fclose(FILE * _File);

extern STD_DIR *std_opendir(const char *name);
extern STD_DIRENT *std_readdir(STD_DIR *d);
extern int32_t std_closedir(STD_DIR *d);

#define atoi		std_atoi
#define Sleep		std_Sleep
#define calloc		std_calloc
#define malloc		std_malloc
#define free		std_free
#define realloc		std_realloc

#define getrandom	std_random

#define strlen		std_strlen
#define strcpy		std_strcpy
#define strncpy		std_strncpy
#define strcat		std_strcat
#define strncat		std_strncat
#define strcmp		std_strcmp
#define stricmp		std_stricmp
#define strncmp		std_strncmp
#define strnicmp	std_strnicmp
#define strchr		std_strchr
#define strrchr		std_strrchr
#define strstr		std_strstr
#define memset		std_memset
#define memcpy		std_memcpy
#define memcmp		std_memcmp
#define strdup		std_strdup
#define strcspn		std_strcspn
#define memmove     std_memmove
#define strtok		std_strtok


#define vsnprintf	std_vsnprintf
#define vscnprintf	std_vscnprintf
#define snprintf	std_snprintf
#define scnprintf	std_scnprintf
#define vsprintf	std_vsprintf
#define sprintf		std_sprintf


#define printf		std_printf



#define tolower		std_tolower
#define pow			std_pow
#define fabs		std_fabs
#define floor		std_floor

#define bzero		std_bzero
#define assert(a)	std_assert((a), __FILE__, __LINE__)
#define htonl		std_htonl
#define ntohl		std_ntohl
#define htons		std_htons
#define ntohs		std_ntohs


#define fopen		std_fopen
#define fseek		std_fseek
#define ftell		std_ftell
#define fread		std_fread
#define fwrite		std_fwrite
#define fclose		std_fclose

#define opendir		std_opendir
#define readdir		std_readdir
#define closedir	std_closedir

#endif//__STD_XXX_H__
