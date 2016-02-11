/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/base/array-init.h"
#include "index.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_index_open,
	const String& index_path)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_index *out = NULL;

	result = git_index_open(&out, index_path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, index) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_index_new)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_index *out = NULL;

	result = git_index_new(&out);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, index) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_index_free,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_free(HHVM_GIT2_V(index_, index));
}

Resource HHVM_FUNCTION(git_index_owner,
	const Resource& index)
{
	git_repository *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_owner(HHVM_GIT2_V(index_, index));
	HHVM_GIT2_V(return_value, repository) = result;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_caps,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_caps(HHVM_GIT2_V(index_, index));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_set_caps,
	const Resource& index,
	int64_t caps)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_set_caps(HHVM_GIT2_V(index_, index), (unsigned int) caps);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_read,
	const Resource& index,
	int64_t force)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_read(HHVM_GIT2_V(index_, index), (int) force);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_write,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_write(HHVM_GIT2_V(index_, index));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_index_path,
	const Resource& index)
{
	const char *result;
	String return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_path(HHVM_GIT2_V(index_, index));

	if (result != NULL) {
		return_value = String(result);
	} else {
		return_value = "";
	}

	return return_value;
}

int64_t HHVM_FUNCTION(git_index_read_tree,
	const Resource& index,
	const Resource& tree)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto tree_ = dyn_cast<Git2Resource>(tree);

	result = git_index_read_tree(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(tree_, tree));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

String HHVM_FUNCTION(git_index_write_tree,
	const Resource& index)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_write_tree(&out, HHVM_GIT2_V(index_, index));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &out);
	return String(return_value);
}

String HHVM_FUNCTION(git_index_write_tree_to,
	const Resource& index,
	const Resource& repo)
{
	int result;
	char return_value[GIT_OID_HEXSZ+1] = {0};

	git_oid out;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_index_write_tree_to(&out, HHVM_GIT2_V(index_, index), HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	git_oid_fmt(return_value, &out);
	return String(return_value);
}

int64_t HHVM_FUNCTION(git_index_entrycount,
	const Resource& index)
{
	size_t result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_entrycount(HHVM_GIT2_V(index_, index));
	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_index_clear,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_clear(HHVM_GIT2_V(index_, index));
}

Resource HHVM_FUNCTION(git_index_get_byindex,
	const Resource& index,
	int64_t n)
{
	const git_index_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_get_byindex(HHVM_GIT2_V(index_, index), (size_t) n);
	//HHVM_GIT2_V(return_value, index_entry) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_index_get_bypath,
	const Resource& index,
	const String& path,
	int64_t stage)
{
	const git_index_entry *result;
	auto return_value = req::make<Git2Resource>();

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_get_bypath(HHVM_GIT2_V(index_, index), path.c_str(), (int) stage);
	//HHVM_GIT2_V(return_value, index_entry) = result; todo return as array
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_index_remove,
	const Resource& index,
	const String& path,
	int64_t stage)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_remove(HHVM_GIT2_V(index_, index), path.c_str(), (int) stage);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_remove_directory,
	const Resource& index,
	const String& dir,
	int64_t stage)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_remove_directory(HHVM_GIT2_V(index_, index), dir.c_str(), (int) stage);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_add,
	const Resource& index,
	const Array& source_entry)
{
    git_index_entry *entry;
	int result;
	int64_t return_value;
    git_oid id;
    
    if (git_oid_fromstr(&id,  source_entry[String("oid")].toString().c_str())) {
        const git_error *error = giterr_last();
        SystemLib::throwInvalidArgumentExceptionObject(error->message);
    }
    
    entry = (git_index_entry*) malloc(sizeof(git_index_entry*));
    
    entry->ctime.seconds = (git_time_t) 0; //todo
    entry->ctime.nanoseconds = (unsigned int) 0; //todo
    entry->mtime.seconds = (git_time_t) 0; //todo
    entry->mtime.nanoseconds = (unsigned int) 0; //todo
    entry->dev = (unsigned int) source_entry[String("dev")].toInt64();
    entry->ino = (unsigned int) source_entry[String("ino")].toInt64();
    entry->mode = (unsigned int) source_entry[String("mode")].toInt64();
    entry->uid = (unsigned int) source_entry[String("uid")].toInt64();
    entry->gid = (unsigned int) source_entry[String("gid")].toInt64();
    entry->file_size = (git_off_t) source_entry[String("file_size")].toInt64();
    entry->oid = id;
    entry->flags = (unsigned short) source_entry[String("flags")].toInt64();
    entry->flags_extended = (unsigned short) source_entry[String("flags_extended")].toInt64();
    entry->path = source_entry[String("path")].toString().mutableData();
    
	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_add(HHVM_GIT2_V(index_, index), entry);
	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_entry_stage,
	const Resource& entry)
{
	int result;
	int64_t return_value;

	auto entry_ = dyn_cast<Git2Resource>(entry);

	result = git_index_entry_stage(HHVM_GIT2_V(entry_, index_entry));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_add_bypath,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_add_bypath(HHVM_GIT2_V(index_, index), path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_remove_bypath,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_remove_bypath(HHVM_GIT2_V(index_, index), path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_add_all,
	const Resource& index,
	const Resource& pathspec,
	int64_t flags,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_index_matched_path_cb callback_ = NULL;
	void *payload_ = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);
	callback_ = NULL;

	result = git_index_add_all(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(pathspec_, strarray), (unsigned int) flags, /* todo */ callback_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_remove_all,
	const Resource& index,
	const Resource& pathspec,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_index_matched_path_cb callback_ = NULL;
	void *payload_ = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);
	callback_ = NULL;

	result = git_index_remove_all(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(pathspec_, strarray), /* todo */ callback_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_update_all,
	const Resource& index,
	const Resource& pathspec,
	const Variant& callback,
	const Variant& payload)
{
	int result;
	int64_t return_value;

	git_index_matched_path_cb callback_ = NULL;
	void *payload_ = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto pathspec_ = dyn_cast<Git2Resource>(pathspec);
	callback_ = NULL;

	result = git_index_update_all(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(pathspec_, strarray), /* todo */ callback_, payload_);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_find,
	int64_t at_pos,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_find((size_t*) at_pos, HHVM_GIT2_V(index_, index), path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_index_conflict_add,
	const Resource& index,
	const Resource& ancestor_entry,
	const Resource& our_entry,
	const Resource& their_entry)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);
	auto ancestor_entry_ = dyn_cast<Git2Resource>(ancestor_entry);
	auto our_entry_ = dyn_cast<Git2Resource>(our_entry);
	auto their_entry_ = dyn_cast<Git2Resource>(their_entry);

	result = git_index_conflict_add(HHVM_GIT2_V(index_, index), HHVM_GIT2_V(ancestor_entry_, index_entry), HHVM_GIT2_V(our_entry_, index_entry), HHVM_GIT2_V(their_entry_, index_entry));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Array HHVM_FUNCTION(git_index_conflict_get,
	const Resource& index,
	const String& path)
{
    Array return_value;
    Array ancestor, our, their;

	const git_index_entry *ancestor_out = NULL, *our_out = NULL, *their_out = NULL;
	char ancestor_buf[GIT_OID_HEXSZ+1] = {0};
    char our_buf[GIT_OID_HEXSZ+1] = {0};
    char their_buf[GIT_OID_HEXSZ+1] = {0};
    
	auto index_ = dyn_cast<Git2Resource>(index);

    git_index_conflict_get(&ancestor_out, &our_out, &their_out, HHVM_GIT2_V(index_, index), path.c_str());
    
    git_oid_fmt(ancestor_buf, &ancestor_out->oid);
    ancestor = make_map_array("ctime", 0, //todo
                              "mtime", 0, //todo
                              "dev", (int64_t) ancestor_out->dev,
                              "ino", (int64_t) ancestor_out->ino,
                              "mode", (int64_t) ancestor_out->mode,
                              "uid", (int64_t) ancestor_out->uid,
                              "gid", (int64_t) ancestor_out->gid,
                              "file_size", (int64_t) ancestor_out->file_size,
                              "oid", String(ancestor_buf),
                              "flags", (int64_t) ancestor_out->flags,
                              "flags_extended", (int64_t) ancestor_out->flags_extended,
                              "path", String(ancestor_out->path));
    
    git_oid_fmt(our_buf, &our_out->oid);
    our = make_map_array("ctime", 0, //todo
                         "mtime", 0, //todo
                         "dev", (int64_t) our_out->dev,
                         "ino", (int64_t) our_out->ino,
                         "mode", (int64_t) our_out->mode,
                         "uid", (int64_t) our_out->uid,
                         "gid", (int64_t) our_out->gid,
                         "file_sSize", (int64_t) our_out->file_size,
                         "oid", String(our_buf),
                         "flags", (int64_t) our_out->flags,
                         "flags_extended", (int64_t) our_out->flags_extended,
                         "path", String(our_out->path));
    
    git_oid_fmt(their_buf, &their_out->oid);
    their = make_map_array("ctime", 0, //todo
                           "mtime", 0, //todo
                           "dev", (int64_t) their_out->dev,
                           "ino", (int64_t) their_out->ino,
                           "mode", (int64_t) their_out->mode,
                           "uid", (int64_t) their_out->uid,
                           "gid", (int64_t) their_out->gid,
                           "file_size", (int64_t) their_out->file_size,
                           "oid", String(their_buf),
                           "flags", (int64_t) their_out->flags,
                           "flags_extended", (int64_t) their_out->flags_extended,
                           "path", String(their_out->path));
    
    return_value = make_map_array("ancestor", ancestor, "our", our, "their", their);

    return return_value;
}

int64_t HHVM_FUNCTION(git_index_conflict_remove,
	const Resource& index,
	const String& path)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_conflict_remove(HHVM_GIT2_V(index_, index), path.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_index_conflict_cleanup,
	const Resource& index)
{

	auto index_ = dyn_cast<Git2Resource>(index);

	git_index_conflict_cleanup(HHVM_GIT2_V(index_, index));
}

int64_t HHVM_FUNCTION(git_index_has_conflicts,
	const Resource& index)
{
	int result;
	int64_t return_value;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_has_conflicts(HHVM_GIT2_V(index_, index));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_index_conflict_iterator_new,
	const Resource& index)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_index_conflict_iterator *iterator_out = NULL;

	auto index_ = dyn_cast<Git2Resource>(index);

	result = git_index_conflict_iterator_new(&iterator_out, HHVM_GIT2_V(index_, index));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, index_conflict_iterator) = iterator_out;
	return Resource(return_value);
}

Array HHVM_FUNCTION(git_index_conflict_next,
	const Resource& iterator)
{
    int result;
	Array return_value;
    Array ancestor, our, their;
    
    const git_index_entry *ancestor_out = NULL, *our_out = NULL, *their_out = NULL;
    char ancestor_buf[GIT_OID_HEXSZ+1] = {0};
    char our_buf[GIT_OID_HEXSZ+1] = {0};
    char their_buf[GIT_OID_HEXSZ+1] = {0};

	auto iterator_ = dyn_cast<Git2Resource>(iterator);

    result = git_index_conflict_next(&ancestor_out, &our_out, &their_out, HHVM_GIT2_V(iterator_, index_conflict_iterator));

	if (result == GIT_ITEROVER) {
		/* todo return nullptr */
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	} else if (result != GIT_OK) {
        SystemLib::throwInvalidArgumentExceptionObject(giterr_last()->message);
    }
    
    git_oid_fmt(ancestor_buf, &ancestor_out->oid);
    ancestor = make_map_array("ctime", 0, //todo
                              "mtime", 0, //todo
                              "dev", (int64_t) ancestor_out->dev,
                              "ino", (int64_t) ancestor_out->ino,
                              "mode", (int64_t) ancestor_out->mode,
                              "uid", (int64_t) ancestor_out->uid,
                              "gid", (int64_t) ancestor_out->gid,
                              "file_size", (int64_t) ancestor_out->file_size,
                              "oid", String(ancestor_buf),
                              "flags", (int64_t) ancestor_out->flags,
                              "flags_extended", (int64_t) ancestor_out->flags_extended,
                              "path", String(ancestor_out->path));
    
    git_oid_fmt(our_buf, &our_out->oid);
    our = make_map_array("ctime", 0, //todo
                         "mtime", 0, //todo
                         "dev", (int64_t) our_out->dev,
                         "ino", (int64_t) our_out->ino,
                         "mode", (int64_t) our_out->mode,
                         "uid", (int64_t) our_out->uid,
                         "gid", (int64_t) our_out->gid,
                         "file_sSize", (int64_t) our_out->file_size,
                         "oid", String(our_buf),
                         "flags", (int64_t) our_out->flags,
                         "flags_extended", (int64_t) our_out->flags_extended,
                         "path", String(our_out->path));
    
    git_oid_fmt(their_buf, &their_out->oid);
    their = make_map_array("ctime", 0, //todo
                           "mtime", 0, //todo
                           "dev", (int64_t) their_out->dev,
                           "ino", (int64_t) their_out->ino,
                           "mode", (int64_t) their_out->mode,
                           "uid", (int64_t) their_out->uid,
                           "gid", (int64_t) their_out->gid,
                           "file_size", (int64_t) their_out->file_size,
                           "oid", String(their_buf),
                           "flags", (int64_t) their_out->flags,
                           "flags_extended", (int64_t) their_out->flags_extended,
                           "path", String(their_out->path));
    
    return_value = make_map_array("ancestor", ancestor, "our", our, "their", their);
	
    return return_value;
}

void HHVM_FUNCTION(git_index_conflict_iterator_free,
	const Resource& iterator)
{

	auto iterator_ = dyn_cast<Git2Resource>(iterator);

	git_index_conflict_iterator_free(HHVM_GIT2_V(iterator_, index_conflict_iterator));
}

