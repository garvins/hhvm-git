/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_GRAPH_H
#define HHVM_GIT2_GRAPH_H


using namespace HPHP;

int64_t HHVM_FUNCTION(git_graph_ahead_behind,
	int64_t ahead,
	int64_t behind,
	const Resource& repo,
	const String& local,
	const String& upstream);

#endif

