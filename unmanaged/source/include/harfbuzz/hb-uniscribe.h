/*
 * Copyright © 2011  Google, Inc.
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Google Author(s): Behdad Esfahbod
 */

#ifndef HB_UNISCRIBE_H
#define HB_UNISCRIBE_H

#include "hb.h"

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <windows.h>
#include <usp10.h>

typedef HRESULT WINAPI (*SIOT)(const WCHAR*,int,int,const SCRIPT_CONTROL*,const SCRIPT_STATE*,SCRIPT_ITEM*,OPENTYPE_TAG*,int*);
typedef HRESULT WINAPI (*SSOT)(HDC,SCRIPT_CACHE*,SCRIPT_ANALYSIS*,OPENTYPE_TAG,OPENTYPE_TAG,int*,TEXTRANGE_PROPERTIES**,int,const WCHAR*,int,int,WORD*,SCRIPT_CHARPROP*,WORD*,SCRIPT_GLYPHPROP*,int*);
typedef HRESULT WINAPI (*SPOT)(HDC,SCRIPT_CACHE*,SCRIPT_ANALYSIS*,OPENTYPE_TAG,OPENTYPE_TAG,int*,TEXTRANGE_PROPERTIES**,int,const WCHAR*,const WORD*,const SCRIPT_CHARPROP*,int,const WORD*,const SCRIPT_GLYPHPROP*,int,int*,GOFFSET*,ABC*);

HB_BEGIN_DECLS


LOGFONTW *
hb_uniscribe_font_get_logfontw (hb_font_t *font);

HFONT
hb_uniscribe_font_get_hfont (hb_font_t *font);


HB_END_DECLS

#endif /* HB_UNISCRIBE_H */
