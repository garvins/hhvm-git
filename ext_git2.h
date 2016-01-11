#ifndef EXT_GIT2_H
#define EXT_GIT2_H

#define HHVM_GIT2_V(git2, type) git2->type
#define HHVM_GIT2_V_N(git2, type) (git2 && git2->type) ? git2->type : NULL

#include "hphp/runtime/ext/extension.h"

#include "git2.h"
#include "git2/cred_helpers.h"
#include "git2/odb_backend.h"
#include "git2/trace.h"
#include "git2/sys/commit.h"
#include "git2/sys/config.h"
#include "git2/sys/filter.h"
#include "git2/sys/index.h"
#include "git2/sys/odb_backend.h"
#include "git2/sys/refdb_backend.h"
#include "git2/sys/reflog.h"
#include "git2/sys/refs.h"
#include "git2/sys/repository.h"

#include <stdlib.h>

enum hhvm_git2_resource_type {
	HHVM_GIT2_TYPE_BLAME_OPTIONS,
	HHVM_GIT2_TYPE_BLAME_HUNK,
	HHVM_GIT2_TYPE_BLAME,
	HHVM_GIT2_TYPE_BRANCH_ITERATOR,
	HHVM_GIT2_TYPE_BUF,
	HHVM_GIT2_TYPE_CHECKOUT_OPTS,
	HHVM_GIT2_TYPE_CLONE_OPTIONS,
	HHVM_GIT2_TYPE_CONFIG_ENTRY,
	HHVM_GIT2_TYPE_CONFIG_ITERATOR,
	HHVM_GIT2_TYPE_CVAR_MAP,
	HHVM_GIT2_TYPE_CRED_USERPASS_PAYLOAD,
	HHVM_GIT2_TYPE_DIFF,
	HHVM_GIT2_TYPE_DIFF_FILE,
	HHVM_GIT2_TYPE_DIFF_DELTA,
	HHVM_GIT2_TYPE_DIFF_OPTIONS,
	HHVM_GIT2_TYPE_DIFF_HUNK,
	HHVM_GIT2_TYPE_DIFF_LINE,
	HHVM_GIT2_TYPE_DIFF_SIMILARITY_METRIC,
	HHVM_GIT2_TYPE_DIFF_FIND_OPTIONS,
	HHVM_GIT2_TYPE_ERROR,
	HHVM_GIT2_TYPE_FILTER,
	HHVM_GIT2_TYPE_FILTER_LIST,
	HHVM_GIT2_TYPE_INDEX_TIME,
	HHVM_GIT2_TYPE_INDEX_ENTRY,
	HHVM_GIT2_TYPE_INDEXER,
	HHVM_GIT2_TYPE_MERGE_TREE_OPTS,
	HHVM_GIT2_TYPE_MERGE_OPTS,
	HHVM_GIT2_TYPE_NOTE_ITERATOR,
	HHVM_GIT2_TYPE_OID,
	HHVM_GIT2_TYPE_OID_SHORTEN,
	HHVM_GIT2_TYPE_PATCH,
	HHVM_GIT2_TYPE_PATHSPEC,
	HHVM_GIT2_TYPE_PATHSPEC_MATCH_LIST,
	HHVM_GIT2_TYPE_PUSH_OPTIONS,
	HHVM_GIT2_TYPE_REPOSITORY_INIT_OPTIONS,
	HHVM_GIT2_TYPE_REVSPEC,
	HHVM_GIT2_TYPE_STATUS_OPTIONS,
	HHVM_GIT2_TYPE_STATUS_ENTRY,
	HHVM_GIT2_TYPE_STRARRAY,
	HHVM_GIT2_TYPE_CRED,
	HHVM_GIT2_TYPE_CRED_USERPASS_PLAINTEXT,
	HHVM_GIT2_TYPE_CRED_SSH_KEY,
	HHVM_GIT2_TYPE_CRED_SSH_CUSTOM,
	HHVM_GIT2_TYPE_CRED_DEFAULT,
	HHVM_GIT2_TYPE_TRANSPORT,
	HHVM_GIT2_TYPE_SMART_SUBTRANSPORT,
	HHVM_GIT2_TYPE_SMART_SUBTRANSPORT_STREAM,
	HHVM_GIT2_TYPE_SMART_SUBTRANSPORT_DEFINITION,
	HHVM_GIT2_TYPE_ODB,
	HHVM_GIT2_TYPE_ODB_BACKEND,
	HHVM_GIT2_TYPE_ODB_OBJECT,
	HHVM_GIT2_TYPE_ODB_STREAM,
	HHVM_GIT2_TYPE_ODB_WRITEPACK,
	HHVM_GIT2_TYPE_REFDB,
	HHVM_GIT2_TYPE_REFDB_BACKEND,
	HHVM_GIT2_TYPE_REPOSITORY,
	HHVM_GIT2_TYPE_OBJECT,
	HHVM_GIT2_TYPE_REVWALK,
	HHVM_GIT2_TYPE_TAG,
	HHVM_GIT2_TYPE_BLOB,
	HHVM_GIT2_TYPE_COMMIT,
	HHVM_GIT2_TYPE_TREE_ENTRY,
	HHVM_GIT2_TYPE_TREE,
	HHVM_GIT2_TYPE_TREEBUILDER,
	HHVM_GIT2_TYPE_INDEX,
	HHVM_GIT2_TYPE_INDEX_CONFLICT_ITERATOR,
	HHVM_GIT2_TYPE_CONFIG,
	HHVM_GIT2_TYPE_CONFIG_BACKEND,
	HHVM_GIT2_TYPE_REFLOG_ENTRY,
	HHVM_GIT2_TYPE_REFLOG,
	HHVM_GIT2_TYPE_NOTE,
	HHVM_GIT2_TYPE_PACKBUILDER,
	HHVM_GIT2_TYPE_TIME,
	HHVM_GIT2_TYPE_SIGNATURE,
	HHVM_GIT2_TYPE_REFERENCE,
	HHVM_GIT2_TYPE_REFERENCE_ITERATOR,
	HHVM_GIT2_TYPE_MERGE_HEAD,
	HHVM_GIT2_TYPE_MERGE_RESULT,
	HHVM_GIT2_TYPE_STATUS_LIST,
	HHVM_GIT2_TYPE_REFSPEC,
	HHVM_GIT2_TYPE_REMOTE,
	HHVM_GIT2_TYPE_PUSH,
	HHVM_GIT2_TYPE_REMOTE_HEAD,
	HHVM_GIT2_TYPE_REMOTE_CALLBACKS,
	HHVM_GIT2_TYPE_TRANSFER_PROGRESS,
	HHVM_GIT2_TYPE_SUBMODULE,
	HHVM_GIT2_TYPE_FILTER_SOURCE,
	HHVM_GIT2_TYPE_INDEX_NAME_ENTRY,
	HHVM_GIT2_TYPE_INDEX_REUC_ENTRY,
};


namespace HPHP {
class Git2Resource : public SweepableResourceData {
public:
	DECLARE_RESOURCE_ALLOCATION(Git2Resource)
	CLASSNAME_IS("git2");
	Git2Resource() {}
	virtual ~Git2Resource() {}
	enum hhvm_git2_resource_type type;
	union {
		git_blame_options *blame_options;
		git_blame_hunk *blame_hunk;
		git_blame *blame;
		git_branch_iterator *branch_iterator;
		git_buf *buf;
		git_checkout_opts *checkout_opts;
		git_clone_options *clone_options;
		git_config_entry *config_entry;
		git_config_iterator *config_iterator;
		git_cvar_map *cvar_map;
		git_cred_userpass_payload *cred_userpass_payload;
		git_diff *diff;
		git_diff_file *diff_file;
		git_diff_delta *diff_delta;
		git_diff_options *diff_options;
		git_diff_hunk *diff_hunk;
		git_diff_line *diff_line;
		git_diff_similarity_metric *diff_similarity_metric;
		git_diff_find_options *diff_find_options;
		git_error *error;
		git_filter *filter;
		git_filter_list *filter_list;
		git_index_time *index_time;
		git_index_entry *index_entry;
		git_indexer *indexer;
		git_merge_tree_opts *merge_tree_opts;
		git_merge_opts *merge_opts;
		git_note_iterator *note_iterator;
		git_oid *oid;
		git_oid_shorten *oid_shorten;
		git_patch *patch;
		git_pathspec *pathspec;
		git_pathspec_match_list *pathspec_match_list;
		git_push_options *push_options;
		git_repository_init_options *repository_init_options;
		git_revspec *revspec;
		git_status_options *status_options;
		git_status_entry *status_entry;
		git_strarray *strarray;
		git_cred *cred;
		git_cred_userpass_plaintext *cred_userpass_plaintext;
		git_cred_ssh_key *cred_ssh_key;
		git_cred_ssh_custom *cred_ssh_custom;
		git_cred_default *cred_default;
		git_transport *transport;
		git_smart_subtransport *smart_subtransport;
		git_smart_subtransport_stream *smart_subtransport_stream;
		git_smart_subtransport_definition *smart_subtransport_definition;
		git_odb *odb;
		git_odb_backend *odb_backend;
		git_odb_object *odb_object;
		git_odb_stream *odb_stream;
		git_odb_writepack *odb_writepack;
		git_refdb *refdb;
		git_refdb_backend *refdb_backend;
		git_repository *repository;
		git_object *object;
		git_revwalk *revwalk;
		git_tag *tag;
		git_blob *blob;
		git_commit *commit;
		git_tree_entry *tree_entry;
		git_tree *tree;
		git_treebuilder *treebuilder;
		git_index *index;
		git_index_conflict_iterator *index_conflict_iterator;
		git_config *config;
		git_config_backend *config_backend;
		git_reflog_entry *reflog_entry;
		git_reflog *reflog;
		git_note *note;
		git_packbuilder *packbuilder;
		git_time *time;
		git_signature *signature;
		git_reference *reference;
		git_reference_iterator *reference_iterator;
		git_merge_head *merge_head;
		git_merge_result *merge_result;
		git_status_list *status_list;
		git_refspec *refspec;
		git_remote *remote;
		git_push *push;
		git_remote_head *remote_head;
		git_remote_callbacks *remote_callbacks;
		git_transfer_progress *transfer_progress;
		git_submodule *submodule;
		git_filter_source *filter_source;
		git_index_name_entry *index_name_entry;
		git_index_reuc_entry *index_reuc_entry;
	};
};
}
#endif /* EXT_GIT2_H */
