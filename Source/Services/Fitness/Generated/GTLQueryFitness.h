/* Copyright (c) 2015 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  GTLQueryFitness.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLQueryFitness (13 custom class methods, 23 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLFitnessAggregateBy;
@class GTLFitnessBucketByActivity;
@class GTLFitnessBucketBySession;
@class GTLFitnessBucketByTime;
@class GTLFitnessDataset;
@class GTLFitnessDataSource;
@class GTLFitnessSession;

@interface GTLQueryFitness : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, retain) NSArray *aggregateBy;  // of GTLFitnessAggregateBy
@property (nonatomic, retain) GTLFitnessBucketByActivity *bucketByActivitySegment;
@property (nonatomic, retain) GTLFitnessBucketByActivity *bucketByActivityType;
@property (nonatomic, retain) GTLFitnessBucketBySession *bucketBySession;
@property (nonatomic, retain) GTLFitnessBucketByTime *bucketByTime;
@property (nonatomic, assign) long long currentTimeMillis;
@property (nonatomic, retain) GTLFitnessDataSource *dataSource;
@property (nonatomic, retain) GTLFitnessDataset *dataset;
@property (nonatomic, copy) NSString *datasetId;
@property (nonatomic, copy) NSString *dataSourceId;
@property (nonatomic, retain) NSArray *dataTypeName;  // of NSString
@property (nonatomic, copy) NSString *endTime;
@property (nonatomic, assign) long long endTimeMillis;
@property (nonatomic, assign) BOOL includeDeleted;
@property (nonatomic, assign) NSInteger limit;
@property (nonatomic, assign) long long modifiedTimeMillis;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, retain) GTLFitnessSession *session;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *startTime;
@property (nonatomic, assign) long long startTimeMillis;
@property (nonatomic, copy) NSString *userId;

#pragma mark - "users.dataset" methods
// These create a GTLQueryFitness object.

// Method: fitness.users.dataset.aggregate
// Aggregates data of a certain type or stream into buckets divided by a given
// type of boundary. Multiple data sets of multiple types and from multiple
// sources can be aggreated into exactly one bucket type per request.
//  Required:
//   userId: Aggregate data for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//   startTimeMillis: The start of a window of time. Data that intersects with
//     this time window will be aggregated. The time is in milliseconds since
//     epoch, inclusive.
//   endTimeMillis: The end of a window of time. Data that intersects with this
//     time window will be aggregated. The time is in milliseconds since epoch,
//     inclusive.
//  Optional:
//   aggregateBy: The specification of data to be aggregated. At least one
//     aggregateBy spec must be provided. All data that is specified will be
//     aggregated using the same bucketing criteria. There will be one dataset
//     in the response for every aggregateBy spec.
//   bucketByActivitySegment: Specifies that data be aggregated each activity
//     segment recored for a user. Similar to bucketByActivitySegment, but
//     bucketing is done for each activity segment rather than all segments of
//     the same type. Mutually exclusive of other bucketing specifications.
//   bucketByActivityType: Specifies that data be aggregated by the type of
//     activity being performed when the data was recorded. All data that was
//     recorded during a certain activity type (for the given time range) will
//     be aggregated into the same bucket. Data that was recorded while the user
//     was not active will not be included in the response. Mutually exclusive
//     of other bucketing specifications.
//   bucketBySession: Specifies that data be aggregated by user sessions. Data
//     that does not fall within the time range of a session will not be
//     included in the response. Mutually exclusive of other bucketing
//     specifications.
//   bucketByTime: Specifies that data be aggregated by a single time interval.
//     Mutually exclusive of other bucketing specifications.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityRead
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyRead
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationRead
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessAggregateResponse.
+ (instancetype)queryForUsersDatasetAggregateWithUserId:(NSString *)userId
                                        startTimeMillis:(long long)startTimeMillis
                                          endTimeMillis:(long long)endTimeMillis;

#pragma mark - "users.dataSources" methods
// These create a GTLQueryFitness object.

// Method: fitness.users.dataSources.create
// Creates a new data source that is unique across all data sources belonging to
// this user. The data stream ID field can be omitted and will be generated by
// the server with the correct format. The data stream ID is an ordered
// combination of some fields from the data source. In addition to the data
// source fields reflected into the data source ID, the developer project number
// that is authenticated when creating the data source is included. This
// developer project number is obfuscated when read by any other developer
// reading public data types.
//  Required:
//   userId: Create the data source for the person identified. Use me to
//     indicate the authenticated user. Only me is supported at this time.
//  Optional:
//   dataSource: GTLFitnessDataSource
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataSource.
+ (instancetype)queryForUsersDataSourcesCreateWithUserId:(NSString *)userId;

#pragma mark - "users.dataSources.datasets" methods
// These create a GTLQueryFitness object.

// Method: fitness.users.dataSources.datasets.delete
// Performs an inclusive delete of all data points whose start and end times
// have any overlap with the time range specified by the dataset ID. For most
// data types, the entire data point will be deleted. For data types where the
// time span represents a consistent value (such as
// com.google.activity.segment), and a data point straddles either end point of
// the dataset, only the overlapping portion of the data point will be deleted.
//  Required:
//   userId: Delete a dataset for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source that created the
//     dataset.
//   datasetId: Dataset identifier that is a composite of the minimum data point
//     start time and maximum data point end time represented as nanoseconds
//     from the epoch. The ID is formatted like: "startTime-endTime" where
//     startTime and endTime are 64 bit integers.
//  Optional:
//   currentTimeMillis: The client's current time in milliseconds since epoch.
//   modifiedTimeMillis: When the operation was performed on the client.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationWrite
+ (instancetype)queryForUsersDataSourcesDatasetsDeleteWithUserId:(NSString *)userId
                                                    dataSourceId:(NSString *)dataSourceId
                                                       datasetId:(NSString *)datasetId;

// Method: fitness.users.dataSources.datasets.get
// Returns a dataset containing all data points whose start and end times
// overlap with the specified range of the dataset minimum start time and
// maximum end time. Specifically, any data point whose start time is less than
// or equal to the dataset end time and whose end time is greater than or equal
// to the dataset start time.
//  Required:
//   userId: Retrieve a dataset for the person identified. Use me to indicate
//     the authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source that created the
//     dataset.
//   datasetId: Dataset identifier that is a composite of the minimum data point
//     start time and maximum data point end time represented as nanoseconds
//     from the epoch. The ID is formatted like: "startTime-endTime" where
//     startTime and endTime are 64 bit integers.
//  Optional:
//   limit: If specified, no more than this many data points will be included in
//     the dataset. If the there are more data points in the dataset,
//     nextPageToken will be set in the dataset response.
//   pageToken: The continuation token, which is used to page through large
//     datasets. To get the next page of a dataset, set this parameter to the
//     value of nextPageToken from the previous response. Each subsequent call
//     will yield a partial dataset with data point end timestamps that are
//     strictly smaller than those in the previous partial response.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityRead
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyRead
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationRead
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataset.
+ (instancetype)queryForUsersDataSourcesDatasetsGetWithUserId:(NSString *)userId
                                                 dataSourceId:(NSString *)dataSourceId
                                                    datasetId:(NSString *)datasetId;

// Method: fitness.users.dataSources.datasets.patch
// Adds data points to a dataset. The dataset need not be previously created.
// All points within the given dataset will be returned with subsquent calls to
// retrieve this dataset. Data points can belong to more than one dataset. This
// method does not use patch semantics.
//  Required:
//   userId: Patch a dataset for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source that created the
//     dataset.
//   datasetId: Dataset identifier that is a composite of the minimum data point
//     start time and maximum data point end time represented as nanoseconds
//     from the epoch. The ID is formatted like: "startTime-endTime" where
//     startTime and endTime are 64 bit integers.
//  Optional:
//   dataset: GTLFitnessDataset
//   currentTimeMillis: The client's current time in milliseconds since epoch.
//     Note that the minStartTimeNs and maxEndTimeNs properties in the request
//     body are in nanoseconds instead of milliseconds.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataset.
+ (instancetype)queryForUsersDataSourcesDatasetsPatchWithUserId:(NSString *)userId
                                                   dataSourceId:(NSString *)dataSourceId
                                                      datasetId:(NSString *)datasetId;

#pragma mark - "users.dataSources" methods
// These create a GTLQueryFitness object.

// Method: fitness.users.dataSources.delete
// Delete the data source if there are no datapoints associated with it
//  Required:
//   userId: Retrieve a data source for the person identified. Use me to
//     indicate the authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source to delete.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataSource.
+ (instancetype)queryForUsersDataSourcesDeleteWithUserId:(NSString *)userId
                                            dataSourceId:(NSString *)dataSourceId;

// Method: fitness.users.dataSources.get
// Returns a data source identified by a data stream ID.
//  Required:
//   userId: Retrieve a data source for the person identified. Use me to
//     indicate the authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityRead
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyRead
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationRead
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataSource.
+ (instancetype)queryForUsersDataSourcesGetWithUserId:(NSString *)userId
                                         dataSourceId:(NSString *)dataSourceId;

// Method: fitness.users.dataSources.list
// Lists all data sources that are visible to the developer, using the OAuth
// scopes provided. The list is not exhaustive: the user may have private data
// sources that are only visible to other developers or calls using other
// scopes.
//  Required:
//   userId: List data sources for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//  Optional:
//   dataTypeName: The names of data types to include in the list. If not
//     specified, all data sources will be returned.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityRead
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyRead
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationRead
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessListDataSourcesResponse.
+ (instancetype)queryForUsersDataSourcesListWithUserId:(NSString *)userId;

// Method: fitness.users.dataSources.patch
// Updates a given data source. It is an error to modify the data source's data
// stream ID, data type, type, stream name or device information apart from the
// device version. Changing these fields would require a new unique data stream
// ID and separate data source.
// Data sources are identified by their data stream ID. This method supports
// patch semantics.
//  Required:
//   userId: Update the data source for the person identified. Use me to
//     indicate the authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source to update.
//  Optional:
//   dataSource: GTLFitnessDataSource
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataSource.
+ (instancetype)queryForUsersDataSourcesPatchWithUserId:(NSString *)userId
                                           dataSourceId:(NSString *)dataSourceId;

// Method: fitness.users.dataSources.update
// Updates a given data source. It is an error to modify the data source's data
// stream ID, data type, type, stream name or device information apart from the
// device version. Changing these fields would require a new unique data stream
// ID and separate data source.
// Data sources are identified by their data stream ID.
//  Required:
//   userId: Update the data source for the person identified. Use me to
//     indicate the authenticated user. Only me is supported at this time.
//   dataSourceId: The data stream ID of the data source to update.
//  Optional:
//   dataSource: GTLFitnessDataSource
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessDataSource.
+ (instancetype)queryForUsersDataSourcesUpdateWithUserId:(NSString *)userId
                                            dataSourceId:(NSString *)dataSourceId;

#pragma mark - "users.sessions" methods
// These create a GTLQueryFitness object.

// Method: fitness.users.sessions.delete
// Deletes a session specified by the given session ID.
//  Required:
//   userId: Delete a session for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//   sessionId: The ID of the session to be deleted.
//  Optional:
//   currentTimeMillis: The client's current time in milliseconds since epoch.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
+ (instancetype)queryForUsersSessionsDeleteWithUserId:(NSString *)userId
                                            sessionId:(NSString *)sessionId;

// Method: fitness.users.sessions.list
// Lists sessions previously created.
//  Required:
//   userId: List sessions for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//  Optional:
//   endTime: An RFC3339 timestamp. Only sessions ending between the start and
//     end times will be included in the response.
//   includeDeleted: If true, deleted sessions will be returned. When set to
//     true, sessions returned in this response will only have an ID and will
//     not have any other fields.
//   pageToken: The continuation token, which is used to page through large
//     result sets. To get the next page of results, set this parameter to the
//     value of nextPageToken from the previous response.
//   startTime: An RFC3339 timestamp. Only sessions ending between the start and
//     end times will be included in the response.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityRead
//   kGTLAuthScopeFitnessActivityWrite
//   kGTLAuthScopeFitnessBodyRead
//   kGTLAuthScopeFitnessBodyWrite
//   kGTLAuthScopeFitnessLocationRead
//   kGTLAuthScopeFitnessLocationWrite
// Fetches a GTLFitnessListSessionsResponse.
+ (instancetype)queryForUsersSessionsListWithUserId:(NSString *)userId;

// Method: fitness.users.sessions.update
// Updates or insert a given session.
//  Required:
//   userId: Create sessions for the person identified. Use me to indicate the
//     authenticated user. Only me is supported at this time.
//   sessionId: The ID of the session to be created.
//  Optional:
//   session: GTLFitnessSession
//   currentTimeMillis: The client's current time in milliseconds since epoch.
//  Authorization scope(s):
//   kGTLAuthScopeFitnessActivityWrite
// Fetches a GTLFitnessSession.
+ (instancetype)queryForUsersSessionsUpdateWithUserId:(NSString *)userId
                                            sessionId:(NSString *)sessionId;

@end
