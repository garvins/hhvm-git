/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_PACK_H
#define HHVM_GIT2_PACK_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_packbuilder_new,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_packbuilder_set_threads,
	const Resource& pb,
	int64_t n);

int64_t HHVM_FUNCTION(git_packbuilder_insert,
	const Resource& pb,
	const String& id,
	const String& name);

int64_t HHVM_FUNCTION(git_packbuilder_insert_tree,
	const Resource& pb,
	const String& id);

int64_t HHVM_FUNCTION(git_packbuilder_insert_commit,
	const Resource& pb,
	const String& id);

int64_t HHVM_FUNCTION(git_packbuilder_write,
	const Resource& pb,
	const String& path,
	int64_t mode,
	const Variant& progress_cb,
	const Variant& progress_cb_payload);

String HHVM_FUNCTION(git_packbuilder_hash,
	const Resource& pb);

int64_t HHVM_FUNCTION(git_packbuilder_foreach,
	const Resource& pb,
	const Variant& cb,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_packbuilder_object_count,
	const Resource& pb);

int64_t HHVM_FUNCTION(git_packbuilder_written,
	const Resource& pb);

int64_t HHVM_FUNCTION(git_packbuilder_set_callbacks,
	const Resource& pb,
	const Variant& progress_cb,
	const Variant& progress_cb_payload);

void HHVM_FUNCTION(git_packbuilder_free,
	const Resource& pb);

#endif

