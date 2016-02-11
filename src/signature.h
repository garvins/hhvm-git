/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SIGNATURE_H
#define HHVM_GIT2_SIGNATURE_H

#include "../ext_git2.h"

using namespace HPHP;

Array HHVM_FUNCTION(git_signature_new,
	const String& name,
	const String& email,
	int64_t time,
	int64_t offset);

Array HHVM_FUNCTION(git_signature_now,
	const String& name,
	const String& email);

Array HHVM_FUNCTION(git_signature_default,
	const Resource& repo);

Array HHVM_FUNCTION(git_signature_dup,
	const Array& sig);

void HHVM_FUNCTION(git_signature_free,
	const Array& sig);

#endif

