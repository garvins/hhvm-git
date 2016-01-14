/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "graph.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_graph_ahead_behind,
	int64_t ahead,
	int64_t behind,
	const Resource& repo,
	const String& local,
	const String& upstream)
{
	int result;
	int64_t return_value;

	git_oid local_;
	git_oid upstream_;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	if (git_oid_fromstr(&local_, local.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}
	if (git_oid_fromstr(&upstream_, upstream.c_str()) != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_graph_ahead_behind((size_t*) ahead, (size_t*) behind, HHVM_GIT2_V(repo_, repository), &local_, &upstream_);

	if (result != GIT_OK) {
		SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
	}

	return_value = (int64_t) result;
	return return_value;
}

