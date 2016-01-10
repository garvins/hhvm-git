/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "odb.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_odb_new)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb **out = NULL;

	git_odb_new(out);
	HHVM_GIT2_V(return_value, odb) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_open,
	const String& objects_dir)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb **out = NULL;

	git_odb_open(out, objects_dir.c_str());
	HHVM_GIT2_V(return_value, odb) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_odb_add_disk_alternate,
	const Resource& odb,
	const String& path)
{
	int result;
	int64_t return_value;

	auto odb_ = dyn_cast<Git2Resource>(odb);

	result = git_odb_add_disk_alternate(HHVM_GIT2_V(odb_, odb), path.c_str());
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_odb_free,
	const Resource& db)
{

	auto db_ = dyn_cast<Git2Resource>(db);

	git_odb_free(HHVM_GIT2_V(db_, odb));
}

Resource HHVM_FUNCTION(git_odb_read,
	const Resource& db,
	const String& id)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_object **out = NULL;
	git_oid *id_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_odb_read(out, HHVM_GIT2_V(db_, odb), id_);
	HHVM_GIT2_V(return_value, odb_object) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_read_prefix,
	const Resource& db,
	const String& short_id,
	int64_t len)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_object **out = NULL;
	git_oid *short_id_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	if (git_oid_fromstrn(short_id_, short_id.c_str(), short_id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_odb_read_prefix(out, HHVM_GIT2_V(db_, odb), short_id_, (size_t) len);
	HHVM_GIT2_V(return_value, odb_object) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_odb_read_header,
	int64_t type_out,
	const Resource& db,
	const String& id)
{
	int64_t return_value;

	size_t *len_out = NULL;
	git_oid *id_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_odb_read_header(len_out, (git_otype*) type_out, HHVM_GIT2_V(db_, odb), id_);
	return_value = (int64_t) len_out;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_exists,
	const Resource& db,
	const String& id)
{
	int result;
	int64_t return_value;

	git_oid *id_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	if (git_oid_fromstrn(id_, id.c_str(), id.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	result = git_odb_exists(HHVM_GIT2_V(db_, odb), id_);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_refresh,
	const Resource& db)
{
	int result;
	int64_t return_value;

	auto db_ = dyn_cast<Git2Resource>(db);

	result = git_odb_refresh(HHVM_GIT2_V(db_, odb));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_foreach,
	const Resource& db,
	const Variant& cb,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_odb_foreach_cb cb_ = NULL;
	void *payload_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	cb_ = NULL;

	result = git_odb_foreach(HHVM_GIT2_V(db_, odb), /* todo */ cb_, payload_);
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_odb_write,
	const Resource& odb,
	const Variant& data,
	int64_t len,
	int64_t type)
{
	char *return_value;

	git_oid *out = NULL;
	void *data_ = NULL;

	auto odb_ = dyn_cast<Git2Resource>(odb);

	git_odb_write(out, HHVM_GIT2_V(odb_, odb), data_, (size_t) len, (git_otype) type);
	git_oid_fmt(return_value, out);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_odb_open_wstream,
	const Resource& db,
	int64_t size,
	int64_t type)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_stream **out = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);

	git_odb_open_wstream(out, HHVM_GIT2_V(db_, odb), (size_t) size, (git_otype) type);
	HHVM_GIT2_V(return_value, odb_stream) = *out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_odb_stream_write,
	const Resource& stream,
	const String& buffer,
	int64_t len)
{
	int result;
	int64_t return_value;

	auto stream_ = dyn_cast<Git2Resource>(stream);

	result = git_odb_stream_write(HHVM_GIT2_V(stream_, odb_stream), buffer.c_str(), (size_t) len);
	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_odb_stream_finalize_write,
	const Resource& stream)
{
	char *return_value;

	git_oid *out = NULL;

	auto stream_ = dyn_cast<Git2Resource>(stream);

	git_odb_stream_finalize_write(out, HHVM_GIT2_V(stream_, odb_stream));
	git_oid_fmt(return_value, out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_odb_stream_read,
	const Resource& stream,
	const String& buffer,
	int64_t len)
{
	int result;
	int64_t return_value;

	auto stream_ = dyn_cast<Git2Resource>(stream);

	result = git_odb_stream_read(HHVM_GIT2_V(stream_, odb_stream), buffer.mutableData(), (size_t) len);
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_odb_stream_free,
	const Resource& stream)
{

	auto stream_ = dyn_cast<Git2Resource>(stream);

	git_odb_stream_free(HHVM_GIT2_V(stream_, odb_stream));
}

Resource HHVM_FUNCTION(git_odb_open_rstream,
	const Resource& db,
	const String& oid)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_stream **out = NULL;
	git_oid *oid_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	if (git_oid_fromstrn(oid_, oid.c_str(), oid.length())) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error->message);
	}

	git_odb_open_rstream(out, HHVM_GIT2_V(db_, odb), oid_);
	HHVM_GIT2_V(return_value, odb_stream) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_write_pack,
	const Resource& db,
	const Variant& progress_cb,
	const Variant& progress_payload)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_writepack **out = NULL;
	git_transfer_progress_callback progress_cb_ = NULL;
	void *progress_payload_ = NULL;

	auto db_ = dyn_cast<Git2Resource>(db);
	progress_cb_ = NULL;

	git_odb_write_pack(out, HHVM_GIT2_V(db_, odb), /* todo */ progress_cb_, progress_payload_);
	HHVM_GIT2_V(return_value, odb_writepack) = *out;
	return Resource(return_value);
}

String HHVM_FUNCTION(git_odb_hash,
	const Variant& data,
	int64_t len,
	int64_t type)
{
	char *return_value = NULL;

	git_oid *out = NULL;
	void *data_ = NULL;

	git_odb_hash(out, data_, (size_t) len, (git_otype) type);
	git_oid_fmt(return_value, out);
	return String(return_value);
}

String HHVM_FUNCTION(git_odb_hashfile,
	const String& path,
	int64_t type)
{
	char *return_value = NULL;

	git_oid *out = NULL;

	git_odb_hashfile(out, path.c_str(), (git_otype) type);
	git_oid_fmt(return_value, out);
	return String(return_value);
}

Resource HHVM_FUNCTION(git_odb_object_dup,
	const Resource& source)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_object **dest = NULL;

	auto source_ = dyn_cast<Git2Resource>(source);

	git_odb_object_dup(dest, HHVM_GIT2_V(source_, odb_object));
	HHVM_GIT2_V(return_value, odb_object) = *dest;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_odb_object_free,
	const Resource& object)
{

	auto object_ = dyn_cast<Git2Resource>(object);

	git_odb_object_free(HHVM_GIT2_V(object_, odb_object));
}

String HHVM_FUNCTION(git_odb_object_id,
	const Resource& object)
{
	const git_oid *result;
	char *return_value;

	auto object_ = dyn_cast<Git2Resource>(object);

	result = git_odb_object_id(HHVM_GIT2_V(object_, odb_object));
	git_oid_fmt(return_value, result);
	return String(return_value);
}

void HHVM_FUNCTION(git_odb_object_data,
	const Resource& object)
{

	auto object_ = dyn_cast<Git2Resource>(object);

	git_odb_object_data(HHVM_GIT2_V(object_, odb_object));
}

int64_t HHVM_FUNCTION(git_odb_object_size,
	const Resource& object)
{
	size_t result;
	int64_t return_value;

	auto object_ = dyn_cast<Git2Resource>(object);

	result = git_odb_object_size(HHVM_GIT2_V(object_, odb_object));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_object_type,
	const Resource& object)
{
	git_otype result;
	int64_t return_value;

	auto object_ = dyn_cast<Git2Resource>(object);

	result = git_odb_object_type(HHVM_GIT2_V(object_, odb_object));
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_add_backend,
	const Resource& odb,
	const Resource& backend,
	int64_t priority)
{
	int result;
	int64_t return_value;

	auto odb_ = dyn_cast<Git2Resource>(odb);
	auto backend_ = dyn_cast<Git2Resource>(backend);

	result = git_odb_add_backend(HHVM_GIT2_V(odb_, odb), HHVM_GIT2_V(backend_, odb_backend), (int) priority);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_add_alternate,
	const Resource& odb,
	const Resource& backend,
	int64_t priority)
{
	int result;
	int64_t return_value;

	auto odb_ = dyn_cast<Git2Resource>(odb);
	auto backend_ = dyn_cast<Git2Resource>(backend);

	result = git_odb_add_alternate(HHVM_GIT2_V(odb_, odb), HHVM_GIT2_V(backend_, odb_backend), (int) priority);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_odb_num_backends,
	const Resource& odb)
{
	size_t result;
	int64_t return_value;

	auto odb_ = dyn_cast<Git2Resource>(odb);

	result = git_odb_num_backends(HHVM_GIT2_V(odb_, odb));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_odb_get_backend,
	const Resource& odb,
	int64_t pos)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_backend **out = NULL;

	auto odb_ = dyn_cast<Git2Resource>(odb);

	git_odb_get_backend(out, HHVM_GIT2_V(odb_, odb), (size_t) pos);
	HHVM_GIT2_V(return_value, odb_backend) = *out;
	return Resource(return_value);
}

