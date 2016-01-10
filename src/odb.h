/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_ODB_H
#define HHVM_GIT2_ODB_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_odb_new);

Resource HHVM_FUNCTION(git_odb_open,
	const String& objects_dir);

int64_t HHVM_FUNCTION(git_odb_add_disk_alternate,
	const Resource& odb,
	const String& path);

void HHVM_FUNCTION(git_odb_free,
	const Resource& db);

Resource HHVM_FUNCTION(git_odb_read,
	const Resource& db,
	const String& id);

Resource HHVM_FUNCTION(git_odb_read_prefix,
	const Resource& db,
	const String& short_id,
	int64_t len);

int64_t HHVM_FUNCTION(git_odb_read_header,
	int64_t type_out,
	const Resource& db,
	const String& id);

int64_t HHVM_FUNCTION(git_odb_exists,
	const Resource& db,
	const String& id);

int64_t HHVM_FUNCTION(git_odb_refresh,
	const Resource& db);

int64_t HHVM_FUNCTION(git_odb_foreach,
	const Resource& db,
	const Variant& cb,
	const Variant& payload);

String HHVM_FUNCTION(git_odb_write,
	const Resource& odb,
	const Variant& data,
	int64_t len,
	int64_t type);

Resource HHVM_FUNCTION(git_odb_open_wstream,
	const Resource& db,
	int64_t size,
	int64_t type);

int64_t HHVM_FUNCTION(git_odb_stream_write,
	const Resource& stream,
	const String& buffer,
	int64_t len);

String HHVM_FUNCTION(git_odb_stream_finalize_write,
	const Resource& stream);

int64_t HHVM_FUNCTION(git_odb_stream_read,
	const Resource& stream,
	const String& buffer,
	int64_t len);

void HHVM_FUNCTION(git_odb_stream_free,
	const Resource& stream);

Resource HHVM_FUNCTION(git_odb_open_rstream,
	const Resource& db,
	const String& oid);

Resource HHVM_FUNCTION(git_odb_write_pack,
	const Resource& db,
	const Variant& progress_cb,
	const Variant& progress_payload);

String HHVM_FUNCTION(git_odb_hash,
	const Variant& data,
	int64_t len,
	int64_t type);

String HHVM_FUNCTION(git_odb_hashfile,
	const String& path,
	int64_t type);

Resource HHVM_FUNCTION(git_odb_object_dup,
	const Resource& source);

void HHVM_FUNCTION(git_odb_object_free,
	const Resource& object);

String HHVM_FUNCTION(git_odb_object_id,
	const Resource& object);

void HHVM_FUNCTION(git_odb_object_data,
	const Resource& object);

int64_t HHVM_FUNCTION(git_odb_object_size,
	const Resource& object);

int64_t HHVM_FUNCTION(git_odb_object_type,
	const Resource& object);

int64_t HHVM_FUNCTION(git_odb_add_backend,
	const Resource& odb,
	const Resource& backend,
	int64_t priority);

int64_t HHVM_FUNCTION(git_odb_add_alternate,
	const Resource& odb,
	const Resource& backend,
	int64_t priority);

int64_t HHVM_FUNCTION(git_odb_num_backends,
	const Resource& odb);

Resource HHVM_FUNCTION(git_odb_get_backend,
	const Resource& odb,
	int64_t pos);

#endif

