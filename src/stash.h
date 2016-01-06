/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_STASH_H
#define HHVM_GIT2_STASH_H


using namespace HPHP;

String HHVM_FUNCTION(git_stash_save,
	const Resource& repo,
	const Resource& stasher,
	const String& message,
	int64_t flags);

int64_t HHVM_FUNCTION(git_stash_foreach,
	const Resource& repo,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_stash_drop,
	const Resource& repo,
	int64_t index);

#endif

