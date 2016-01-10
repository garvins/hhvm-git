/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_OID_H
#define HHVM_GIT2_OID_H

#include "../ext_git2.h"

using namespace HPHP;

String HHVM_FUNCTION(git_oid_fromstr,
	const String& str);

String HHVM_FUNCTION(git_oid_fromstrp,
	const String& str);

String HHVM_FUNCTION(git_oid_fromstrn,
	const String& str,
	int64_t length);

String HHVM_FUNCTION(git_oid_fromraw,
	const String& raw);

String HHVM_FUNCTION(git_oid_fmt,
	const String& id);

String HHVM_FUNCTION(git_oid_nfmt,
	int64_t n,
	const String& id);

String HHVM_FUNCTION(git_oid_pathfmt,
	const String& id);

String HHVM_FUNCTION(git_oid_allocfmt,
	const String& id);

String HHVM_FUNCTION(git_oid_tostr,
	int64_t n,
	const String& id);

String HHVM_FUNCTION(git_oid_cpy,
	const String& src);

int64_t HHVM_FUNCTION(git_oid_cmp,
	const String& a,
	const String& b);

int64_t HHVM_FUNCTION(git_oid_ncmp,
	const String& a,
	const String& b,
	int64_t len);

int64_t HHVM_FUNCTION(git_oid_streq,
	const String& id,
	const String& str);

int64_t HHVM_FUNCTION(git_oid_strcmp,
	const String& id,
	const String& str);

int64_t HHVM_FUNCTION(git_oid_iszero,
	const String& id);

Resource HHVM_FUNCTION(git_oid_shorten_new,
	int64_t min_length);

int64_t HHVM_FUNCTION(git_oid_shorten_add,
	const Resource& os,
	const String& text_id);

void HHVM_FUNCTION(git_oid_shorten_free,
	const Resource& os);

#endif

