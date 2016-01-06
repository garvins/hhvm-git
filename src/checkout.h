/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_CHECKOUT_H
#define HHVM_GIT2_CHECKOUT_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_checkout_head,
	const Resource& repo,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_checkout_index,
	const Resource& repo,
	const Resource& index,
	const Resource& opts);

int64_t HHVM_FUNCTION(git_checkout_tree,
	const Resource& repo,
	const Resource& treeish,
	const Resource& opts);

#endif

