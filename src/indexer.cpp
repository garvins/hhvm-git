/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/system/systemlib.h"

#include "indexer.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_indexer_new,
	const String& path,
	int64_t mode,
	const Resource& odb,
	const Variant& progress_cb,
	const Variant& progress_cb_payload)
{
	auto return_value = req::make<Git2Resource>();

	git_indexer **out = NULL;
	git_transfer_progress_callback progress_cb_ = NULL;
	void *progress_cb_payload_ = NULL;

	auto odb_ = dyn_cast<Git2Resource>(odb);
	progress_cb_ = NULL;

	git_indexer_new(out, path.c_str(), (unsigned int) mode, HHVM_GIT2_V(odb_, odb), /* todo */ progress_cb_, progress_cb_payload_);
	HHVM_GIT2_V(return_value, indexer) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_indexer_append,
	const Resource& idx,
	const Variant& data,
	int64_t size,
	const Resource& stats)
{
	int result;
	int64_t return_value;

	void *data_ = NULL;

	auto idx_ = dyn_cast<Git2Resource>(idx);
	auto stats_ = dyn_cast<Git2Resource>(stats);

	result = git_indexer_append(HHVM_GIT2_V(idx_, indexer), data_, (size_t) size, HHVM_GIT2_V(stats_, transfer_progress));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_indexer_commit,
	const Resource& idx,
	const Resource& stats)
{
	int result;
	int64_t return_value;

	auto idx_ = dyn_cast<Git2Resource>(idx);
	auto stats_ = dyn_cast<Git2Resource>(stats);

	result = git_indexer_commit(HHVM_GIT2_V(idx_, indexer), HHVM_GIT2_V(stats_, transfer_progress));
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_indexer_hash,
	const Resource& idx)
{
	const git_oid *result;
	char *return_value;

	auto idx_ = dyn_cast<Git2Resource>(idx);

	result = git_indexer_hash(HHVM_GIT2_V(idx_, indexer));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

void HHVM_FUNCTION(git_indexer_free,
	const Resource& idx)
{

	auto idx_ = dyn_cast<Git2Resource>(idx);

	git_indexer_free(HHVM_GIT2_V(idx_, indexer));
}

