#ifndef TRS_FS_SMB_H
#define TRS_FS_SMB_H

#include "smb2.h"

#include "trs-fs.h"

#define SMB_KEY_URL "smb_url"
#define SMB_KEY_USER "smb_user"
#define SMB_KEY_PASSWD "smb_passwd"


class TRS_FS_SMB : virtual public TRS_FS {
private:
  char* smb_url = NULL;
  struct smb2_context *smb2 = NULL;

  const char* init();
public:
  TRS_FS_SMB();
  TRS_FS_SMB(const char* url, const char* user, const char* passwd);
  virtual ~TRS_FS_SMB();
  void f_log(const char* msg);
  FRESULT f_open (
                  FIL* fp,           /* [OUT] Pointer to the file object structure */
                  const TCHAR* path, /* [IN] File name */
                  BYTE mode          /* [IN] Mode flags */
                  );
  FRESULT f_opendir (
                     DIR_* dp,           /* [OUT] Pointer to the directory object structure */
                     const TCHAR* path  /* [IN] Directory name */
                     );
  FRESULT f_write (
                   FIL* fp,          /* [IN] Pointer to the file object structure */
                   const void* buff, /* [IN] Pointer to the data to be written */
                   UINT btw,         /* [IN] Number of bytes to write */
                   UINT* bw          /* [OUT] Pointer to the variable to return number of bytes written */
                   );
  FRESULT f_read (
                  FIL* fp,     /* [IN] File object */
                  void* buff,  /* [OUT] Buffer to store read data */
                  UINT btr,    /* [IN] Number of bytes to read */
                  UINT* br     /* [OUT] Number of bytes read */
                  );
  FRESULT f_readdir (
                     DIR_* dp,      /* [IN] Directory object */
                     FILINFO* fno  /* [OUT] File information structure */
                     );
  FSIZE_t f_tell (
                  FIL* fp   /* [IN] File object */
                  );
  FRESULT f_sync (
                  FIL* fp     /* [IN] File object */
                  );
  FRESULT f_lseek (
                   FIL*    fp,  /* [IN] File object */
                   FSIZE_t ofs  /* [IN] File read/write pointer */
                   );
  FRESULT f_close (
                   FIL* fp     /* [IN] Pointer to the file object */
                   );
  FRESULT f_unlink (
                    const TCHAR* path  /* [IN] Object name */
                    );
  FRESULT f_stat (
                  const TCHAR* path,  /* [IN] Object name */
                  FILINFO* fno        /* [OUT] FILINFO structure */
                  );

};

#endif
