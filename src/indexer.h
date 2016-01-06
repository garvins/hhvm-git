/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_INDEXER_H
#define HHVM_GIT2_INDEXER_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_indexer_new,
	const String& path,
	int64_t mode,
	const Resource& odb,
	const Variant& progress_cb,
	const Variant& progress_cb_payload);

int64_t HHVM_FUNCTION(git_indexer_append,
	const Resource& idx,
	const Variant& data,
	int64_t size,
	const Resource& stats);

int64_t HHVM_FUNCTION(git_indexer_commit,
	const Resource& idx,
	const Resource& stats);

String HHVM_FUNCTION(git_indexer_hash,
	const Resource& idx);

void HHVM_FUNCTION(git_indexer_free,
	const Resource& idx);

#endif

