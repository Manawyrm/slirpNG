/*
 * ppp.h - PPP global declarations.
 *
 * Copyright (c) 1989 Carnegie Mellon University.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by Carnegie Mellon University.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $Id: ppp.h,v 1.1 1993/11/11 03:54:25 paulus Exp $
 */


/*
 * Modified for use with SLiRP by Juha Pirkola  8-May-1995
 */

#include <slirp.h>

#ifndef __PPP_H__
#define __PPP_H__

/*
 * Data Link Layer header = Address, Control, Protocol.
 */
#define ALLSTATIONS	0xff	/* All-Stations Address */
#define UI		0x03	/* Unnumbered Information */
#define LCP		0xc021	/* Link Control Protocol */
#define IPCP		0x8021	/* IP Control Protocol */
#define UPAP		0xc023	/* User/Password Authentication Protocol */
#define CHAP            0xc223  /* Cryptographic Handshake Protocol */
#define LQR		0xc025	/* Link Quality Report protocol */
#define IP_VJ_COMP	0x002d	/* VJ TCP compressed IP packet */
#define DLLHEADERLEN	(sizeof (u_char) + sizeof (u_char) + sizeof (u_short))
#define MTU		1500	/* Default MTU */


#ifdef __STDC__
void real_do_syslog _P((int priority, const char *format, ...));
#else
void real_do_syslog ();
#endif

#define do_syslog if(debug)real_do_syslog

void print_string _P((char *, int, void (*) _P((void *, char *, ...)), void *));

int bad_ip_adrs(u_int32_t addr);
void novm __P((char *));
void auth_peer_fail(int unit, int protocol);
void auth_withpeer_fail(int unit, int protocol);
void auth_peer_success(int unit, int protocol);
void auth_withpeer_success(int unit, int protocol);
int auth_ip_addr(int unit, u_int32_t addr);
void link_established(int unit);
void link_down(int unit);
void link_required(int unit);
void link_terminated(int unit);
void check_auth_options();
void check_access(FILE *f, char *filename);

#endif /* __PPP_H__ */
