/* -*- c -*- */

#ifndef __NEW_SERVER_PROTO_H__
#define __NEW_SERVER_PROTO_H__

/* Copyright (C) 2006-2017 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "ejudge/ej_types.h"

#include <stdio.h>
#include <time.h>

#define NEW_SERVER_PROT_PACKET_MAGIC (0xe352)
struct new_server_prot_packet
{
  unsigned short magic;
  short id;
};

// client->serve requests
enum
{
  NEW_SRV_CMD_PASS_FD = 1,
  NEW_SRV_CMD_STOP,
  NEW_SRV_CMD_RESTART,
  NEW_SRV_CMD_HTTP_REQUEST,

  NEW_SRV_CMD_LAST,
};

enum
{
  NEW_SRV_ACTION_LOGIN_PAGE = 1,
  NEW_SRV_ACTION_MAIN_PAGE = 2,
  NEW_SRV_ACTION_COOKIE_LOGIN = 3, /* number needed for super-serve */
  NEW_SRV_ACTION_VIEW_USERS,
  NEW_SRV_ACTION_VIEW_ONLINE_USERS,
  NEW_SRV_ACTION_USERS_REMOVE_REGISTRATIONS,
  NEW_SRV_ACTION_USERS_SET_PENDING,
  NEW_SRV_ACTION_USERS_SET_OK,
  NEW_SRV_ACTION_USERS_SET_REJECTED,
  NEW_SRV_ACTION_USERS_SET_INVISIBLE,
  NEW_SRV_ACTION_USERS_CLEAR_INVISIBLE,
  NEW_SRV_ACTION_USERS_SET_BANNED,
  NEW_SRV_ACTION_USERS_CLEAR_BANNED,
  NEW_SRV_ACTION_USERS_SET_LOCKED,
  NEW_SRV_ACTION_USERS_CLEAR_LOCKED,
  NEW_SRV_ACTION_USERS_SET_INCOMPLETE,
  NEW_SRV_ACTION_USERS_CLEAR_INCOMPLETE,
  NEW_SRV_ACTION_USERS_SET_DISQUALIFIED,
  NEW_SRV_ACTION_USERS_CLEAR_DISQUALIFIED,
  NEW_SRV_ACTION_USERS_ADD_BY_LOGIN,
  NEW_SRV_ACTION_USERS_ADD_BY_USER_ID,
  NEW_SRV_ACTION_PRIV_USERS_VIEW,
  NEW_SRV_ACTION_PRIV_USERS_REMOVE,
  NEW_SRV_ACTION_PRIV_USERS_ADD_OBSERVER,
  NEW_SRV_ACTION_PRIV_USERS_DEL_OBSERVER,
  NEW_SRV_ACTION_PRIV_USERS_ADD_EXAMINER,
  NEW_SRV_ACTION_PRIV_USERS_DEL_EXAMINER,
  NEW_SRV_ACTION_PRIV_USERS_ADD_CHIEF_EXAMINER,
  NEW_SRV_ACTION_PRIV_USERS_DEL_CHIEF_EXAMINER,
  NEW_SRV_ACTION_PRIV_USERS_ADD_COORDINATOR,
  NEW_SRV_ACTION_PRIV_USERS_DEL_COORDINATOR,
  NEW_SRV_ACTION_PRIV_USERS_ADD_BY_LOGIN,
  NEW_SRV_ACTION_PRIV_USERS_ADD_BY_USER_ID,
  NEW_SRV_ACTION_CHANGE_LANGUAGE,
  NEW_SRV_ACTION_CHANGE_PASSWORD,
  NEW_SRV_ACTION_VIEW_SOURCE,
  NEW_SRV_ACTION_VIEW_REPORT,
  NEW_SRV_ACTION_PRINT_RUN,
  NEW_SRV_ACTION_VIEW_CLAR,
  NEW_SRV_ACTION_SUBMIT_RUN,
  NEW_SRV_ACTION_SUBMIT_CLAR,
  NEW_SRV_ACTION_START_CONTEST,
  NEW_SRV_ACTION_STOP_CONTEST,
  NEW_SRV_ACTION_CONTINUE_CONTEST,
  NEW_SRV_ACTION_SCHEDULE,
  NEW_SRV_ACTION_CHANGE_DURATION,
  NEW_SRV_ACTION_UPDATE_STANDINGS_1,
  NEW_SRV_ACTION_RESET_1,
  NEW_SRV_ACTION_SUSPEND,
  NEW_SRV_ACTION_RESUME,
  NEW_SRV_ACTION_TEST_SUSPEND,
  NEW_SRV_ACTION_TEST_RESUME,
  NEW_SRV_ACTION_PRINT_SUSPEND,
  NEW_SRV_ACTION_PRINT_RESUME,
  NEW_SRV_ACTION_SET_JUDGING_MODE,
  NEW_SRV_ACTION_SET_ACCEPTING_MODE,
  NEW_SRV_ACTION_SET_TESTING_FINISHED_FLAG,
  NEW_SRV_ACTION_CLEAR_TESTING_FINISHED_FLAG,
  NEW_SRV_ACTION_GENERATE_PASSWORDS_1,
  NEW_SRV_ACTION_CLEAR_PASSWORDS_1,
  NEW_SRV_ACTION_GENERATE_REG_PASSWORDS_1,
  NEW_SRV_ACTION_RELOAD_SERVER,
  NEW_SRV_ACTION_PRIV_SUBMIT_CLAR,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_COMMENT,
  NEW_SRV_ACTION_RESET_FILTER,
  NEW_SRV_ACTION_CLEAR_RUN,
  NEW_SRV_ACTION_CHANGE_STATUS,
  NEW_SRV_ACTION_REJUDGE_ALL_1,
  NEW_SRV_ACTION_REJUDGE_SUSPENDED_1,
  NEW_SRV_ACTION_REJUDGE_DISPLAYED_1,
  NEW_SRV_ACTION_FULL_REJUDGE_DISPLAYED_1,
  NEW_SRV_ACTION_SQUEEZE_RUNS,
  NEW_SRV_ACTION_RESET_CLAR_FILTER,
  NEW_SRV_ACTION_LOGOUT,
  NEW_SRV_ACTION_CHANGE_RUN_USER_ID,
  NEW_SRV_ACTION_CHANGE_RUN_USER_LOGIN,
  NEW_SRV_ACTION_CHANGE_RUN_PROB_ID,
  NEW_SRV_ACTION_CHANGE_RUN_VARIANT,
  NEW_SRV_ACTION_CHANGE_RUN_LANG_ID,
  NEW_SRV_ACTION_CHANGE_RUN_IS_IMPORTED,
  NEW_SRV_ACTION_CHANGE_RUN_IS_HIDDEN,
  NEW_SRV_ACTION_CHANGE_RUN_IS_EXAMINABLE,
  NEW_SRV_ACTION_CHANGE_RUN_IS_READONLY,
  NEW_SRV_ACTION_CHANGE_RUN_IS_MARKED,
  NEW_SRV_ACTION_CHANGE_RUN_IS_SAVED,
  NEW_SRV_ACTION_CHANGE_RUN_STATUS,
  NEW_SRV_ACTION_CHANGE_RUN_TEST,
  NEW_SRV_ACTION_CHANGE_RUN_SCORE,
  NEW_SRV_ACTION_CHANGE_RUN_SCORE_ADJ,
  NEW_SRV_ACTION_CHANGE_RUN_PAGES,
  NEW_SRV_ACTION_DOWNLOAD_RUN,
  NEW_SRV_ACTION_COMPARE_RUNS,
  NEW_SRV_ACTION_UPLOAD_REPORT,
  NEW_SRV_ACTION_STANDINGS,
  NEW_SRV_ACTION_REJUDGE_PROBLEM_1,
  NEW_SRV_ACTION_CLAR_REPLY,
  NEW_SRV_ACTION_CLAR_REPLY_ALL,
  NEW_SRV_ACTION_CLAR_REPLY_READ_PROBLEM,
  NEW_SRV_ACTION_CLAR_REPLY_NO_COMMENTS,
  NEW_SRV_ACTION_CLAR_REPLY_YES,
  NEW_SRV_ACTION_CLAR_REPLY_NO,
  NEW_SRV_ACTION_REJUDGE_DISPLAYED_2,
  NEW_SRV_ACTION_FULL_REJUDGE_DISPLAYED_2,
  NEW_SRV_ACTION_REJUDGE_PROBLEM_2,
  NEW_SRV_ACTION_REJUDGE_ALL_2,
  NEW_SRV_ACTION_REJUDGE_SUSPENDED_2,
  NEW_SRV_ACTION_VIEW_TEST_INPUT,
  NEW_SRV_ACTION_VIEW_TEST_ANSWER,
  NEW_SRV_ACTION_VIEW_TEST_INFO,
  NEW_SRV_ACTION_VIEW_TEST_OUTPUT,
  NEW_SRV_ACTION_VIEW_TEST_ERROR,
  NEW_SRV_ACTION_VIEW_TEST_CHECKER,
  NEW_SRV_ACTION_VIEW_AUDIT_LOG,
  NEW_SRV_ACTION_UPDATE_STANDINGS_2,
  NEW_SRV_ACTION_RESET_2,
  NEW_SRV_ACTION_GENERATE_PASSWORDS_2,
  NEW_SRV_ACTION_CLEAR_PASSWORDS_2,
  NEW_SRV_ACTION_GENERATE_REG_PASSWORDS_2,
  NEW_SRV_ACTION_VIEW_CNTS_PWDS,
  NEW_SRV_ACTION_VIEW_REG_PWDS,
  NEW_SRV_ACTION_TOGGLE_VISIBILITY,
  NEW_SRV_ACTION_TOGGLE_BAN,
  NEW_SRV_ACTION_TOGGLE_LOCK,
  NEW_SRV_ACTION_TOGGLE_INCOMPLETENESS,
  NEW_SRV_ACTION_SET_DISQUALIFICATION,
  NEW_SRV_ACTION_CLEAR_DISQUALIFICATION,
  NEW_SRV_ACTION_USER_CHANGE_STATUS,
  NEW_SRV_ACTION_VIEW_USER_INFO,
  NEW_SRV_ACTION_ISSUE_WARNING,
  NEW_SRV_ACTION_NEW_RUN_FORM,
  NEW_SRV_ACTION_NEW_RUN,
  NEW_SRV_ACTION_VIEW_USER_DUMP,
  NEW_SRV_ACTION_FORGOT_PASSWORD_1,
  NEW_SRV_ACTION_FORGOT_PASSWORD_2,
  NEW_SRV_ACTION_FORGOT_PASSWORD_3,
  NEW_SRV_ACTION_SUBMIT_APPEAL,
  NEW_SRV_ACTION_VIEW_PROBLEM_SUMMARY,
  NEW_SRV_ACTION_VIEW_PROBLEM_STATEMENTS,
  NEW_SRV_ACTION_VIEW_PROBLEM_SUBMIT,
  NEW_SRV_ACTION_VIEW_SUBMISSIONS,
  NEW_SRV_ACTION_VIEW_CLAR_SUBMIT,
  NEW_SRV_ACTION_VIEW_CLARS,
  NEW_SRV_ACTION_VIEW_SETTINGS,
  NEW_SRV_ACTION_VIRTUAL_START,
  NEW_SRV_ACTION_VIRTUAL_STOP,
  NEW_SRV_ACTION_VIRTUAL_RESTART,
  NEW_SRV_ACTION_VIEW_USER_REPORT,
  NEW_SRV_ACTION_DOWNLOAD_ARCHIVE_1,
  NEW_SRV_ACTION_DOWNLOAD_ARCHIVE_2,
  NEW_SRV_ACTION_UPLOAD_RUNLOG_CSV_1,
  NEW_SRV_ACTION_UPLOAD_RUNLOG_CSV_2,
  NEW_SRV_ACTION_VIEW_RUNS_DUMP,
  NEW_SRV_ACTION_EXPORT_XML_RUNS,
  NEW_SRV_ACTION_WRITE_XML_RUNS,
  NEW_SRV_ACTION_WRITE_XML_RUNS_WITH_SRC,
  NEW_SRV_ACTION_UPLOAD_RUNLOG_XML_1,
  NEW_SRV_ACTION_UPLOAD_RUNLOG_XML_2,
  NEW_SRV_ACTION_LOGIN,         /* for new-server-cmd */
  NEW_SRV_ACTION_DUMP_PROBLEMS,
  NEW_SRV_ACTION_DUMP_LANGUAGES,
  NEW_SRV_ACTION_SOFT_UPDATE_STANDINGS,
  NEW_SRV_ACTION_HAS_TRANSIENT_RUNS,
  NEW_SRV_ACTION_DUMP_RUN_STATUS,
  NEW_SRV_ACTION_DUMP_SOURCE,
  NEW_SRV_ACTION_DUMP_CLAR,
  NEW_SRV_ACTION_GET_CONTEST_NAME,
  NEW_SRV_ACTION_GET_CONTEST_TYPE,
  NEW_SRV_ACTION_GET_CONTEST_STATUS,
  NEW_SRV_ACTION_GET_CONTEST_SCHED,
  NEW_SRV_ACTION_GET_CONTEST_DURATION,
  NEW_SRV_ACTION_GET_CONTEST_DESCRIPTION,
  NEW_SRV_ACTION_DUMP_MASTER_RUNS,
  NEW_SRV_ACTION_DUMP_REPORT,
  NEW_SRV_ACTION_FULL_UPLOAD_RUNLOG_XML,
  NEW_SRV_ACTION_JSON_USER_STATE,
  NEW_SRV_ACTION_VIEW_STARTSTOP,
  NEW_SRV_ACTION_CLEAR_DISPLAYED_1,
  NEW_SRV_ACTION_CLEAR_DISPLAYED_2,
  NEW_SRV_ACTION_IGNORE_DISPLAYED_1,
  NEW_SRV_ACTION_IGNORE_DISPLAYED_2,
  NEW_SRV_ACTION_DISQUALIFY_DISPLAYED_1,
  NEW_SRV_ACTION_DISQUALIFY_DISPLAYED_2,
  NEW_SRV_ACTION_TOKENIZE_DISPLAYED_1,
  NEW_SRV_ACTION_TOKENIZE_DISPLAYED_2,
  NEW_SRV_ACTION_UPDATE_ANSWER,
  NEW_SRV_ACTION_UPSOLVING_CONFIG_1,
  NEW_SRV_ACTION_UPSOLVING_CONFIG_2,
  NEW_SRV_ACTION_UPSOLVING_CONFIG_3,
  NEW_SRV_ACTION_UPSOLVING_CONFIG_4,
  NEW_SRV_ACTION_EXAMINERS_PAGE,
  NEW_SRV_ACTION_ASSIGN_CHIEF_EXAMINER,
  NEW_SRV_ACTION_ASSIGN_EXAMINER,
  NEW_SRV_ACTION_UNASSIGN_EXAMINER,
  NEW_SRV_ACTION_GET_FILE,
  NEW_SRV_ACTION_PRINT_USER_PROTOCOL,
  NEW_SRV_ACTION_PRINT_USER_FULL_PROTOCOL,
  NEW_SRV_ACTION_PRINT_UFC_PROTOCOL, /* user full cyphered */
  NEW_SRV_ACTION_FORCE_START_VIRTUAL,
  NEW_SRV_ACTION_PRINT_SELECTED_USER_PROTOCOL,
  NEW_SRV_ACTION_PRINT_SELECTED_USER_FULL_PROTOCOL,
  NEW_SRV_ACTION_PRINT_SELECTED_UFC_PROTOCOL, /* user full cyphered */
  NEW_SRV_ACTION_PRINT_PROBLEM_PROTOCOL,
  NEW_SRV_ACTION_ASSIGN_CYPHERS_1,
  NEW_SRV_ACTION_ASSIGN_CYPHERS_2,
  NEW_SRV_ACTION_VIEW_EXAM_INFO,
  NEW_SRV_ACTION_PRIV_SUBMIT_PAGE,
  NEW_SRV_ACTION_USE_TOKEN,
  NEW_SRV_ACTION_GENERATE_TELEGRAM_TOKEN,

  /* new-register stuff */
  NEW_SRV_ACTION_REG_CREATE_ACCOUNT_PAGE,
  NEW_SRV_ACTION_REG_CREATE_ACCOUNT,
  NEW_SRV_ACTION_REG_ACCOUNT_CREATED_PAGE,
  NEW_SRV_ACTION_REG_LOGIN_PAGE,
  NEW_SRV_ACTION_REG_LOGIN,
  NEW_SRV_ACTION_REG_VIEW_GENERAL,
  NEW_SRV_ACTION_REG_VIEW_CONTESTANTS,
  NEW_SRV_ACTION_REG_VIEW_RESERVES,
  NEW_SRV_ACTION_REG_VIEW_COACHES,
  NEW_SRV_ACTION_REG_VIEW_ADVISORS,
  NEW_SRV_ACTION_REG_VIEW_GUESTS,
  NEW_SRV_ACTION_REG_ADD_MEMBER_PAGE,
  NEW_SRV_ACTION_REG_EDIT_GENERAL_PAGE,
  NEW_SRV_ACTION_REG_EDIT_MEMBER_PAGE,
  NEW_SRV_ACTION_REG_MOVE_MEMBER,
  NEW_SRV_ACTION_REG_REMOVE_MEMBER,
  NEW_SRV_ACTION_REG_SUBMIT_GENERAL_EDITING,
  NEW_SRV_ACTION_REG_CANCEL_GENERAL_EDITING,
  NEW_SRV_ACTION_REG_SUBMIT_MEMBER_EDITING,
  NEW_SRV_ACTION_REG_CANCEL_MEMBER_EDITING,
  NEW_SRV_ACTION_REG_REGISTER,
  NEW_SRV_ACTION_REG_DATA_EDIT,

  // more master stuff
  NEW_SRV_ACTION_PRIO_FORM,
  NEW_SRV_ACTION_SET_PRIORITIES,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_COMMENT_AND_IGNORE,
  NEW_SRV_ACTION_VIEW_USER_IPS,
  NEW_SRV_ACTION_VIEW_IP_USERS,
  NEW_SRV_ACTION_CHANGE_FINISH_TIME,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_COMMENT_AND_OK,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_COMMENT_AND_REJECT,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_COMMENT_AND_SUMMON,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_JUST_IGNORE,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_JUST_OK,
  NEW_SRV_ACTION_PRIV_SUBMIT_RUN_JUST_SUMMON,
  NEW_SRV_ACTION_PRIV_SET_RUN_REJECTED,
  NEW_SRV_ACTION_VIEW_TESTING_QUEUE,
  NEW_SRV_ACTION_TESTING_DELETE,
  NEW_SRV_ACTION_TESTING_UP,
  NEW_SRV_ACTION_TESTING_DOWN,
  NEW_SRV_ACTION_TESTING_DELETE_ALL,
  NEW_SRV_ACTION_TESTING_UP_ALL,
  NEW_SRV_ACTION_TESTING_DOWN_ALL,
  NEW_SRV_ACTION_INVOKER_DELETE,
  NEW_SRV_ACTION_INVOKER_STOP,
  NEW_SRV_ACTION_INVOKER_DOWN,
  NEW_SRV_ACTION_MARK_DISPLAYED_2,
  NEW_SRV_ACTION_UNMARK_DISPLAYED_2,
  NEW_SRV_ACTION_SET_STAND_FILTER,
  NEW_SRV_ACTION_RESET_STAND_FILTER,
  NEW_SRV_ACTION_ADMIN_CONTEST_SETTINGS,
  NEW_SRV_ACTION_ADMIN_CHANGE_ONLINE_VIEW_SOURCE,
  NEW_SRV_ACTION_ADMIN_CHANGE_ONLINE_VIEW_REPORT,
  NEW_SRV_ACTION_ADMIN_CHANGE_ONLINE_VIEW_JUDGE_SCORE,
  NEW_SRV_ACTION_ADMIN_CHANGE_ONLINE_FINAL_VISIBILITY,
  NEW_SRV_ACTION_RELOAD_SERVER_2,
  NEW_SRV_ACTION_CHANGE_RUN_FIELDS,
  NEW_SRV_ACTION_PRIV_EDIT_CLAR_PAGE,
  NEW_SRV_ACTION_PRIV_EDIT_CLAR_ACTION,
  NEW_SRV_ACTION_PRIV_EDIT_RUN_PAGE,
  NEW_SRV_ACTION_PRIV_EDIT_RUN_ACTION,
  NEW_SRV_ACTION_PING,
  NEW_SRV_ACTION_SUBMIT_RUN_BATCH,
  NEW_SRV_ACTION_CONTESTS_PAGE,
  NEW_SRV_ACTION_CONTEST_BATCH,
  NEW_SRV_ACTION_RELOAD_STATEMENT,
  NEW_SRV_ACTION_RELOAD_STATEMENT_ALL,
  NEW_SRV_ACTION_ADD_REVIEW_COMMENT,
  NEW_SRV_ACTION_RELOAD_SERVER_ALL,
  NEW_SRV_ACTION_VIEW_USERS_NEW_PAGE,
  NEW_SRV_ACTION_VIEW_USERS_NEW_AJAX,
  NEW_SRV_ACTION_USERS_SET_STATUS,
  NEW_SRV_ACTION_USERS_CHANGE_FLAGS,
  NEW_SRV_ACTION_REG_UPLOAD_AVATAR,
  NEW_SRV_ACTION_GET_AVATAR,
  NEW_SRV_ACTION_REG_CROP_AVATAR_PAGE,
  NEW_SRV_ACTION_REG_SAVE_CROPPED_AVATAR_AJAX,
  NEW_SRV_ACTION_PRIV_REGENERATE_CONTENT,
  NEW_SRV_ACTION_RELOAD_CONTEST_PAGES,
  NEW_SRV_ACTION_RELOAD_ALL_CONTEST_PAGES,

  NEW_SRV_ACTION_LAST,
};

// internal page indices
enum
{
  NEW_SRV_INT_STANDINGS = 1,
  NEW_SRV_INT_PUBLIC_LOG,

  NEW_SRV_INT_LAST,
};

// serve->client replies
enum
{
  NEW_SRV_RPL_OK = 0,

  NEW_SRV_RPL_LAST,
};

// serve error message codes
enum
{
  NEW_SRV_ERR_NO_ERROR = 0,
  NEW_SRV_ERR_UNKNOWN_ERROR,
  NEW_SRV_ERR_BAD_SOCKET_NAME,
  NEW_SRV_ERR_SYSTEM_ERROR,
  NEW_SRV_ERR_CONNECT_FAILED,
  NEW_SRV_ERR_WRITE_ERROR,
  NEW_SRV_ERR_NOT_CONNECTED,
  NEW_SRV_ERR_READ_ERROR,
  NEW_SRV_ERR_UNEXPECTED_EOF,
  NEW_SRV_ERR_PACKET_TOO_BIG,
  NEW_SRV_ERR_PACKET_TOO_SMALL,
  NEW_SRV_ERR_PROTOCOL_ERROR,
  NEW_SRV_ERR_PARAM_OUT_OF_RANGE,

  NEW_SRV_ERR_INV_USER_ID,
  NEW_SRV_ERR_REGISTRATION_FAILED,
  NEW_SRV_ERR_USER_REMOVAL_FAILED,
  NEW_SRV_ERR_USER_STATUS_CHANGE_FAILED,
  NEW_SRV_ERR_USER_FLAGS_CHANGE_FAILED,
  NEW_SRV_ERR_INV_USER_LOGIN,
  NEW_SRV_ERR_USER_LOGIN_NONEXISTANT,
  NEW_SRV_ERR_PRIV_USER_REMOVAL_FAILED,
  NEW_SRV_ERR_PRIV_USER_ROLE_ADD_FAILED,
  NEW_SRV_ERR_PRIV_USER_ROLE_DEL_FAILED,
  NEW_SRV_ERR_INV_USER_ROLE,
  NEW_SRV_ERR_INV_TIME_SPEC,
  NEW_SRV_ERR_CONTEST_ALREADY_FINISHED,
  NEW_SRV_ERR_CONTEST_ALREADY_STARTED,
  NEW_SRV_ERR_INV_DUR_SPEC,
  NEW_SRV_ERR_DUR_TOO_SMALL,
  NEW_SRV_ERR_PERMISSION_DENIED,
  NEW_SRV_ERR_CONTEST_NOT_STARTED,
  NEW_SRV_ERR_CONTEST_NOT_STOPPED,
  NEW_SRV_ERR_CANNOT_CONTINUE_CONTEST,
  NEW_SRV_ERR_CONTEST_NOT_FINISHED,
  NEW_SRV_ERR_INSUFFICIENT_DURATION,
  NEW_SRV_ERR_INV_LOCALE_ID,
  NEW_SRV_ERR_SESSION_UPDATE_FAILED,
  NEW_SRV_ERR_LANG_DISABLED,
  NEW_SRV_ERR_LANG_NOT_AVAIL_FOR_PROBLEM,
  NEW_SRV_ERR_LANG_DISABLED_FOR_PROBLEM,
  NEW_SRV_ERR_CANNOT_DETECT_CONTENT_TYPE,
  NEW_SRV_ERR_CONTENT_TYPE_NOT_AVAILABLE,
  NEW_SRV_ERR_CONTENT_TYPE_DISABLED,
  NEW_SRV_ERR_RUNLOG_UPDATE_FAILED,
  NEW_SRV_ERR_DISK_WRITE_ERROR,
  NEW_SRV_ERR_USER_ID_NONEXISTANT,
  NEW_SRV_ERR_CONFLICTING_USER_ID_LOGIN,
  NEW_SRV_ERR_SUBJECT_TOO_LONG,
  NEW_SRV_ERR_SUBJECT_EMPTY,
  NEW_SRV_ERR_MESSAGE_TOO_LONG,
  NEW_SRV_ERR_MESSAGE_EMPTY,
  NEW_SRV_ERR_CLARLOG_UPDATE_FAILED,
  NEW_SRV_ERR_INV_CLAR_ID,
  NEW_SRV_ERR_CANNOT_REPLY_TO_JUDGE,
  NEW_SRV_ERR_DISK_READ_ERROR,
  NEW_SRV_ERR_INV_STATUS,
  NEW_SRV_ERR_NO_RUNS_TO_REJUDGE,
  NEW_SRV_ERR_RUN_TO_COMPARE_UNSPECIFIED,
  NEW_SRV_ERR_INV_RUN_TO_COMPARE,
  NEW_SRV_ERR_RUN_COMPARE_FAILED,
  NEW_SRV_ERR_INV_PROB_ID,
  NEW_SRV_ERR_SOURCE_UNAVAILABLE,
  NEW_SRV_ERR_SOURCE_NONEXISTANT,
  NEW_SRV_ERR_INV_LANG_ID,
  NEW_SRV_ERR_INV_TEST,
  NEW_SRV_ERR_OLD_PWD_TOO_LONG,
  NEW_SRV_ERR_NEW_PWD_MISMATCH,
  NEW_SRV_ERR_NEW_PWD_TOO_LONG,
  NEW_SRV_ERR_PWD_UPDATE_FAILED,
  NEW_SRV_ERR_RUN_ID_UNDEFINED,
  NEW_SRV_ERR_INV_RUN_ID,
  NEW_SRV_ERR_RUN_ID_OUT_OF_RANGE,
  NEW_SRV_ERR_RUNLOG_READ_FAILED,
  NEW_SRV_ERR_PRINTING_DISABLED,
  NEW_SRV_ERR_ALREADY_PRINTED,
  NEW_SRV_ERR_PRINT_QUOTA_EXCEEDED,
  NEW_SRV_ERR_PRINTING_FAILED,
  NEW_SRV_ERR_CLIENTS_SUSPENDED,
  NEW_SRV_ERR_RUN_QUOTA_EXCEEDED,
  NEW_SRV_ERR_PROB_UNAVAILABLE,
  NEW_SRV_ERR_PROB_DEADLINE_EXPIRED,
  NEW_SRV_ERR_VARIANT_UNASSIGNED,
  NEW_SRV_ERR_DUPLICATE_SUBMIT,
  NEW_SRV_ERR_PROB_ALREADY_SOLVED,
  NEW_SRV_ERR_NOT_ALL_REQ_SOLVED,
  NEW_SRV_ERR_CLARS_DISABLED,
  NEW_SRV_ERR_CLAR_QUOTA_EXCEEDED,
  NEW_SRV_ERR_SOURCE_VIEW_DISABLED,
  NEW_SRV_ERR_REPORT_UNAVAILABLE,
  NEW_SRV_ERR_REPORT_VIEW_DISABLED,
  NEW_SRV_ERR_REPORT_NONEXISTANT,
  NEW_SRV_ERR_TEST_NONEXISTANT,
  NEW_SRV_ERR_CHECKSUMMING_FAILED,
  NEW_SRV_ERR_OUTPUT_ERROR,
  NEW_SRV_ERR_TEST_UNAVAILABLE,
  NEW_SRV_ERR_INV_VARIANT,
  NEW_SRV_ERR_PWD_GENERATION_FAILED,
  NEW_SRV_ERR_TEAM_PWD_DISABLED,
  NEW_SRV_ERR_APPEALS_DISABLED,
  NEW_SRV_ERR_APPEALS_FINISHED,
  NEW_SRV_ERR_NOT_VIRTUAL,
  NEW_SRV_ERR_VIRTUAL_NOT_STARTED,
  NEW_SRV_ERR_UNHANDLED_ACTION,
  NEW_SRV_ERR_UNDEFINED_USER_ID_LOGIN,
  NEW_SRV_ERR_INV_PARAM,
  NEW_SRV_ERR_BINARY_FILE,
  NEW_SRV_ERR_INV_SCORE,
  NEW_SRV_ERR_INV_SCORE_ADJ,
  NEW_SRV_ERR_INV_PAGES,
  NEW_SRV_ERR_RUN_READ_ONLY,
  NEW_SRV_ERR_INV_WARN_TEXT,
  NEW_SRV_ERR_WARN_TEXT_EMPTY,
  NEW_SRV_ERR_INV_WARN_CMT,
  NEW_SRV_ERR_SUBMIT_EMPTY,
  NEW_SRV_ERR_AUDIT_LOG_NONEXISTANT,
  NEW_SRV_ERR_INV_RUN_SELECTION,
  NEW_SRV_ERR_INV_DIR_STRUCT,
  NEW_SRV_ERR_MKDIR_FAILED,
  NEW_SRV_ERR_TAR_FAILED,
  NEW_SRV_ERR_FILE_UNSPECIFIED,
  NEW_SRV_ERR_FILE_EMPTY,
  NEW_SRV_ERR_TRY_AGAIN,
  NEW_SRV_ERR_NOT_SUPPORTED,
  NEW_SRV_ERR_INV_ACTION,
  NEW_SRV_ERR_INV_CONTEST_ID,
  NEW_SRV_ERR_INV_ROLE,
  NEW_SRV_ERR_USERLIST_SERVER_DOWN,
  NEW_SRV_ERR_INTERNAL,
  NEW_SRV_ERR_TRANSIENT_RUNS,
  NEW_SRV_ERR_INV_ANSWER,
  NEW_SRV_ERR_INV_FILTER_EXPR,
  NEW_SRV_ERR_CONTEST_UNLOADED,
  NEW_SRV_ERR_PENDING_IMPORT_EXISTS,
  NEW_SRV_ERR_ANSWER_UNSPECIFIED,
  NEW_SRV_ERR_LOGIN_BINARY,
  NEW_SRV_ERR_LOGIN_UNSPECIFIED,
  NEW_SRV_ERR_LOGIN_INV_CHARS,
  NEW_SRV_ERR_EMAIL_BINARY,
  NEW_SRV_ERR_EMAIL_UNSPECIFIED,
  NEW_SRV_ERR_EMAIL_INV_CHARS,
  NEW_SRV_ERR_UL_CONNECT_FAILED,
  NEW_SRV_ERR_PLUGIN_NOT_AVAIL,
  NEW_SRV_ERR_INV_FILE_NAME,
  NEW_SRV_ERR_VIRTUAL_START_FAILED,
  NEW_SRV_ERR_INV_CHAR,
  NEW_SRV_ERR_DATABASE_FAILED,
  NEW_SRV_ERR_PROB_CONFIG,
  NEW_SRV_ERR_PROB_TOO_MANY_ATTEMPTS,
  NEW_SRV_ERR_INV_SESSION,
  NEW_SRV_ERR_REGISTRATION_INCOMPLETE,
  NEW_SRV_ERR_SERVICE_NOT_AVAILABLE,
  NEW_SRV_ERR_DISQUALIFIED,
  NEW_SRV_ERR_SIMPLE_REGISTERED,
  NEW_SRV_ERR_CNTS_UNAVAILABLE,
  NEW_SRV_ERR_OPERATION_FAILED,

  NEW_SRV_ERR_LAST,
};

#define EJUDGE_NEW_SERVER_SOCKET_DEFAULT "/tmp/new-server-socket"

struct new_server_prot_http_request
{
  struct new_server_prot_packet b;
  int arg_num;
  int env_num;
  int param_num;
};

void ns_error(FILE *log_f, int code, ...);
const unsigned char *ns_strerror(int code, ...);
const unsigned char *ns_strerror_2(int code, ...);
const unsigned char *ns_strerror_r(unsigned char *buf, size_t size,
                                   int code, ...);
const unsigned char *ns_error_title(int error_code);

#endif /* __NEW_SERVER_PROTO_H__ */
