#include "UwpShellExtStringsZHCN.h"

#include <tchar.h>

UwpShlExtStringsZHCN::UwpShlExtStringsZHCN()
{
	// Shell ext
#if defined (_DEBUG)
	m_stringsMap[_T("SHELL_EXT_DISPLAY_NAME")] = _T("ʹ�� fHash DEV �����ϣ");
#else
	m_stringsMap[_T("SHELL_EXT_DISPLAY_NAME")] = _T("ʹ�� fHash �����ϣ");
#endif
}
