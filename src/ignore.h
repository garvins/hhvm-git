/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_IGNORE_H
#define HHVM_GIT2_IGNORE_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_ignore_add_rule,
	const Resource& repo,
	const String& rules);

int64_t HHVM_FUNCTION(git_ignore_clear_internal_rules,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_ignore_path_is_ignored,
	int64_t ignored,
	const Resource& repo,
	const String& path);

#endif

