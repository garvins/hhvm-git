/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_SYS_REFS_H
#define HHVM_GIT2_SYS_REFS_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_reference__alloc,
	const String& name,
	const String& oid,
	const String& peel);

Resource HHVM_FUNCTION(git_reference__alloc_symbolic,
	const String& name,
	const String& target);

#endif

