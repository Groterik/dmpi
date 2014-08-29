#ifndef AMPI_ABI_PROXY_H_GUARD
#define AMPI_ABI_PROXY_H_GUARD

#ifndef DAMPI_DLL_NOT_USED
#if defined _WIN32 || defined _CYGWIN_
  #ifdef BUILDING_DLL
    #ifdef _GNUC_
      #define DAMPI_DLL_PUBLIC _attribute_ ((dllexport))
    #else
      #define DAMPI_DLL_PUBLIC _declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef _GNUC_
      #define DAMPI_DLL_PUBLIC _attribute_ ((dllimport))
    #else
      #define DAMPI_DLL_PUBLIC _declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DAMPI_DLL_LOCAL
#else
  #if _GNUC_ >= 4
    #define DAMPI_DLL_PUBLIC _attribute_ ((visibility ("default")))
    #define DAMPI_DLL_LOCAL  _attribute_ ((visibility ("hidden")))
  #else
    #define DAMPI_DLL_PUBLIC
    #define DAMPI_DLL_LOCAL
  #endif
#endif
#else
#define DAMPI_DLL_PUBLIC
#define DAMPI_DLL_LOCAL
#endif

extern "C"
{

const int AMPI_SUCCESS = 0;
const int AMPI_ERR_BUFFER = 1;
const int AMPI_ERR_COUNT = 2;
const int AMPI_ERR_TYPE = 3;
const int AMPI_ERR_TAG = 4;
const int AMPI_ERR_COMM = 5;
const int AMPI_ERR_RANK = 6;
const int AMPI_ERR_REQUEST = 7;
const int AMPI_ERR_ROOT = 8;
const int AMPI_ERR_GROUP = 9;
const int AMPI_ERR_OP = 10;
const int AMPI_ERR_TOPOLOGY = 11;
const int AMPI_ERR_DIMS = 12;
const int AMPI_ERR_ARG = 13;
const int AMPI_ERR_UNKNOWN = 14;
const int AMPI_ERR_TRUNCATE = 15;
const int AMPI_ERR_OTHER = 16;
const int AMPI_ERR_INTERN = 17;
const int AMPI_ERR_IN_STATUS = 18;
const int AMPI_ERR_PENDING = 19;
const int AMPI_ERR_ACCESS = 20;
const int AMPI_ERR_AMODE = 21;
const int AMPI_ERR_ASSERT = 22;
const int AMPI_ERR_BAD_FILE = 23;
const int AMPI_ERR_BASE = 24;
const int AMPI_ERR_CONVERSION = 25;
const int AMPI_ERR_DISP = 26;
const int AMPI_ERR_DUP_DATAREP = 27;
const int AMPI_ERR_FILE_EXISTS = 28;
const int AMPI_ERR_FILE_IN_USE = 29;
const int AMPI_ERR_FILE = 30;
const int AMPI_ERR_INFO_KEY = 31;
const int AMPI_ERR_INFO_NOKEY = 32;
const int AMPI_ERR_INFO_VALUE = 33;
const int AMPI_ERR_INFO = 34;
const int AMPI_ERR_IO = 35;
const int AMPI_ERR_KEYVAL = 36;
const int AMPI_ERR_LOCKTYPE = 37;
const int AMPI_ERR_NAME = 38;
const int AMPI_ERR_NO_MEM = 39;
const int AMPI_ERR_NOT_SAME = 40;
const int AMPI_ERR_NO_SPACE = 41;
const int AMPI_ERR_NO_SUCH_FILE = 42;
const int AMPI_ERR_PORT = 43;
const int AMPI_ERR_QUOTA = 44;
const int AMPI_ERR_READ_ONLY = 45;
const int AMPI_ERR_RMA_CONFLICT = 46;
const int AMPI_ERR_RMA_SYNC = 47;
const int AMPI_ERR_SERVICE = 48;
const int AMPI_ERR_SIZE = 49;
const int AMPI_ERR_SPAWN = 50;
const int AMPI_ERR_UNSUPPORTED_DATAREP = 51;
const int AMPI_ERR_UNSUPPORTED_OPERATION = 52;
const int AMPI_ERR_WIN = 53;
const int AMPI_ERR_LASTCODE = 54;
const int AMPI_ERR_SYSRESOURCE = -2;

// Types
typedef int AMPI_Datatype;
const AMPI_Datatype AMPI_CHAR = 0;
const AMPI_Datatype AMPI_SHORT = 1;
const AMPI_Datatype AMPI_INT = 2;
const AMPI_Datatype AMPI_LONG = 3;
const AMPI_Datatype AMPI_UNSIGNED_CHAR = 4;
const AMPI_Datatype AMPI_UNSIGNED_SHORT = 5;
const AMPI_Datatype AMPI_UNSIGNED_LONG = 6;
const AMPI_Datatype AMPI_UNSIGNED = 7;
const AMPI_Datatype AMPI_FLOAT = 8;
const AMPI_Datatype AMPI_DOUBLE = 9;
const AMPI_Datatype AMPI_LONG_DOUBLE = 10;
const AMPI_Datatype AMPI_LONG_LONG = 11;
const AMPI_Datatype AMPI_UNSIGNED_LONG_LONG = 12;

struct IAMPI_Comm;
typedef IAMPI_Comm* AMPI_Comm;
extern const AMPI_Comm AMPI_COMM_WORLD;

struct IAMPI_Request;
typedef IAMPI_Request* AMPI_Request;

struct IAMPI_Status;
typedef IAMPI_Status* AMPI_Status;

/*
 * Wrappers
 */

DAMPI_DLL_PUBLIC  AMPI_Request AMPI_Request_create();
DAMPI_DLL_PUBLIC  void AMPI_Request_free(AMPI_Request request);
DAMPI_DLL_PUBLIC  AMPI_Status AMPI_Status_create();
DAMPI_DLL_PUBLIC  void AMPI_Status_free(AMPI_Status status);

/*
 * MPI API
 */

DAMPI_DLL_PUBLIC  int AMPI_Abort(AMPI_Comm comm, int errorcode);
//DAMPI_DLL_PUBLIC  int AMPI_Accumulate(void *origin_addr, int origin_count, AMPI_Datatype origin_datatype,
//                                  int target_rank, AMPI_Aint target_disp, int target_count,
//                                  AMPI_Datatype target_datatype, AMPI_Op op, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Add_error_class(int *errorclass);
//DAMPI_DLL_PUBLIC  int AMPI_Add_error_code(int errorclass, int *errorcode);
//DAMPI_DLL_PUBLIC  int AMPI_Add_error_string(int errorcode, char *string);
//DAMPI_DLL_PUBLIC  int AMPI_Address(void *location, AMPI_Aint *address);
//DAMPI_DLL_PUBLIC  int AMPI_Allgather(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                                 void *recvbuf, int recvcount,
//                                 AMPI_Datatype recvtype, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Allgatherv(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                                  void *recvbuf, int *recvcounts,
//                                  int *displs, AMPI_Datatype recvtype, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Alloc_mem(AMPI_Aint size, AMPI_Info info,
//                                 void *baseptr);
//DAMPI_DLL_PUBLIC  int AMPI_Allreduce(void *sendbuf, void *recvbuf, int count,
//                                 AMPI_Datatype datatype, AMPI_Op op, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Alltoall(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                                void *recvbuf, int recvcount,
//                                AMPI_Datatype recvtype, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
//                                 AMPI_Datatype sendtype, void *recvbuf, int *recvcounts,
//                                 int *rdispls, AMPI_Datatype recvtype, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls, AMPI_Datatype *sendtypes,
//                                 void *recvbuf, int *recvcounts, int *rdispls, AMPI_Datatype *recvtypes,
//                                 AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Attr_delete(AMPI_Comm comm, int keyval);
//DAMPI_DLL_PUBLIC  int AMPI_Attr_get(AMPI_Comm comm, int keyval, void *attribute_val, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Attr_put(AMPI_Comm comm, int keyval, void *attribute_val);
DAMPI_DLL_PUBLIC  int AMPI_Barrier(AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Bcast(void *buffer, int count, AMPI_Datatype datatype,
//                             int root, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Bsend(void *buf, int count, AMPI_Datatype datatype,
//                             int dest, int tag, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Bsend_init(void *buf, int count, AMPI_Datatype datatype,
//                                  int dest, int tag, AMPI_Comm comm, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Buffer_attach(void *buffer, int size);
//DAMPI_DLL_PUBLIC  int AMPI_Buffer_detach(void *buffer, int *size);
DAMPI_DLL_PUBLIC  int AMPI_Cancel(AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_coords(AMPI_Comm comm, int rank, int maxdims, int *coords);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_create(AMPI_Comm old_comm, int ndims, int *dims,
//                                   int *periods, int reorder, AMPI_Comm *comm_cart);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_get(AMPI_Comm comm, int maxdims, int *dims,
//                                int *periods, int *coords);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_map(AMPI_Comm comm, int ndims, int *dims,
//                                int *periods, int *newrank);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_rank(AMPI_Comm comm, int *coords, int *rank);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_shift(AMPI_Comm comm, int direction, int disp,
//                                  int *rank_source, int *rank_dest);
//DAMPI_DLL_PUBLIC  int AMPI_Cart_sub(AMPI_Comm comm, int *remain_dims, AMPI_Comm *new_comm);
//DAMPI_DLL_PUBLIC  int AMPI_Cartdim_get(AMPI_Comm comm, int *ndims);
//DAMPI_DLL_PUBLIC  int AMPI_Close_port(char *port_name);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_accept(char *port_name, AMPI_Info info, int root,
//                                   AMPI_Comm comm, AMPI_Comm *newcomm);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Comm_c2f(AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_call_errhandler(AMPI_Comm comm, int errorcode);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_compare(AMPI_Comm comm1, AMPI_Comm comm2, int *result);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_connect(char *port_name, AMPI_Info info, int root,
//                                    AMPI_Comm comm, AMPI_Comm *newcomm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_create_errhandler(AMPI_Comm_errhandler_fn *function,
//                                              AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_create_keyval(AMPI_Comm_copy_attr_function *comm_copy_attr_fn,
//                                          AMPI_Comm_delete_attr_function *comm_delete_attr_fn,
//                                          int *comm_keyval, void *extra_state);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_create(AMPI_Comm comm, AMPI_Group group, AMPI_Comm *newcomm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_delete_attr(AMPI_Comm comm, int comm_keyval);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_disconnect(AMPI_Comm *comm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_dup(AMPI_Comm comm, AMPI_Comm *newcomm);
//DAMPI_DLL_PUBLIC  AMPI_Comm AMPI_Comm_f2c(AMPI_Fint comm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_free_keyval(int *comm_keyval);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_free(AMPI_Comm *comm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_get_attr(AMPI_Comm comm, int comm_keyval,
//                                     void *attribute_val, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_get_errhandler(AMPI_Comm comm, AMPI_Errhandler *erhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_get_name(AMPI_Comm comm, char *comm_name, int *resultlen);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_get_parent(AMPI_Comm *parent);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_group(AMPI_Comm comm, AMPI_Group *group);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_join(int fd, AMPI_Comm *intercomm);
DAMPI_DLL_PUBLIC  int AMPI_Comm_rank(AMPI_Comm comm, int *rank);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_remote_group(AMPI_Comm comm, AMPI_Group *group);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_remote_size(AMPI_Comm comm, int *size);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_set_attr(AMPI_Comm comm, int comm_keyval, void *attribute_val);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_set_errhandler(AMPI_Comm comm, AMPI_Errhandler errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_set_name(AMPI_Comm comm, char *comm_name);
DAMPI_DLL_PUBLIC  int AMPI_Comm_size(AMPI_Comm comm, int *size);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_spawn(char *command, char **argv, int maxprocs, AMPI_Info info,
//                                  int root, AMPI_Comm comm, AMPI_Comm *intercomm,
//                                  int *array_of_errcodes);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_spawn_multiple(int count, char **array_of_commands, char ***array_of_argv,
//                                           int *array_of_maxprocs, AMPI_Info *array_of_info,
//                                           int root, AMPI_Comm comm, AMPI_Comm *intercomm,
//                                           int *array_of_errcodes);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_split(AMPI_Comm comm, int color, int key, AMPI_Comm *newcomm);
//DAMPI_DLL_PUBLIC  int AMPI_Comm_test_inter(AMPI_Comm comm, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Dims_create(int nnodes, int ndims, int *dims);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Errhandler_c2f(AMPI_Errhandler errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Errhandler_create(AMPI_Handler_function *function,
//                                         AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  AMPI_Errhandler AMPI_Errhandler_f2c(AMPI_Fint errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Errhandler_free(AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Errhandler_get(AMPI_Comm comm, AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Errhandler_set(AMPI_Comm comm, AMPI_Errhandler errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Error_class(int errorcode, int *errorclass);
//DAMPI_DLL_PUBLIC  int AMPI_Error_string(int errorcode, char *string, int *resultlen);
//DAMPI_DLL_PUBLIC  int AMPI_Exscan(void *sendbuf, void *recvbuf, int count,
//                              AMPI_Datatype datatype, AMPI_Op op, AMPI_Comm comm);
//#if AMPI_PROVIDE_AMPI_FILE_INTERFACE
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_File_c2f(AMPI_File file);
//DAMPI_DLL_PUBLIC  AMPI_File AMPI_File_f2c(AMPI_Fint file);
//DAMPI_DLL_PUBLIC  int AMPI_File_call_errhandler(AMPI_File fh, int errorcode);
//DAMPI_DLL_PUBLIC  int AMPI_File_create_errhandler(AMPI_File_errhandler_fn *function,
//                                              AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_File_set_errhandler( AMPI_File file, AMPI_Errhandler errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_errhandler( AMPI_File file, AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_File_open(AMPI_Comm comm, char *filename, int amode,
//                                 AMPI_Info info, AMPI_File *fh);
//DAMPI_DLL_PUBLIC  int AMPI_File_close(AMPI_File *fh);
//DAMPI_DLL_PUBLIC  int AMPI_File_delete(char *filename, AMPI_Info info);
//DAMPI_DLL_PUBLIC  int AMPI_File_set_size(AMPI_File fh, AMPI_Offset size);
//DAMPI_DLL_PUBLIC  int AMPI_File_preallocate(AMPI_File fh, AMPI_Offset size);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_size(AMPI_File fh, AMPI_Offset *size);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_group(AMPI_File fh, AMPI_Group *group);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_amode(AMPI_File fh, int *amode);
//DAMPI_DLL_PUBLIC  int AMPI_File_set_info(AMPI_File fh, AMPI_Info info);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_info(AMPI_File fh, AMPI_Info *info_used);
//DAMPI_DLL_PUBLIC  int AMPI_File_set_view(AMPI_File fh, AMPI_Offset disp, AMPI_Datatype etype,
//                                     AMPI_Datatype filetype, char *datarep, AMPI_Info info);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_view(AMPI_File fh, AMPI_Offset *disp,
//                                     AMPI_Datatype *etype,
//                                     AMPI_Datatype *filetype, char *datarep);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_at(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                    int count, AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_at_all(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                        int count, AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_at(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                     int count, AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_at_all(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                         int count, AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_iread_at(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                     int count, AMPI_Datatype datatype, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_File_iwrite_at(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                      int count, AMPI_Datatype datatype, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_File_read(AMPI_File fh, void *buf, int count,
//                                 AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_all(AMPI_File fh, void *buf, int count,
//                                     AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write(AMPI_File fh, void *buf, int count,
//                                  AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_all(AMPI_File fh, void *buf, int count,
//                                      AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_iread(AMPI_File fh, void *buf, int count,
//                                  AMPI_Datatype datatype, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_File_iwrite(AMPI_File fh, void *buf, int count,
//                                   AMPI_Datatype datatype, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_File_seek(AMPI_File fh, AMPI_Offset offset, int whence);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_position(AMPI_File fh, AMPI_Offset *offset);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_byte_offset(AMPI_File fh, AMPI_Offset offset,
//                                            AMPI_Offset *disp);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_shared(AMPI_File fh, void *buf, int count,
//                                        AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_shared(AMPI_File fh, void *buf, int count,
//                     AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_iread_shared(AMPI_File fh, void *buf, int count,
//                                         AMPI_Datatype datatype, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_File_iwrite_shared(AMPI_File fh, void *buf, int count,
//                                          AMPI_Datatype datatype, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_ordered(AMPI_File fh, void *buf, int count,
//                                         AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_ordered(AMPI_File fh, void *buf, int count,
//                                          AMPI_Datatype datatype, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_seek_shared(AMPI_File fh, AMPI_Offset offset, int whence);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_position_shared(AMPI_File fh, AMPI_Offset *offset);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_at_all_begin(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                              int count, AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_at_all_end(AMPI_File fh, void *buf, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_at_all_begin(AMPI_File fh, AMPI_Offset offset, void *buf,
//                                               int count, AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_at_all_end(AMPI_File fh, void *buf, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_all_begin(AMPI_File fh, void *buf, int count,
//                                           AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_all_end(AMPI_File fh, void *buf, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_all_begin(AMPI_File fh, void *buf, int count,
//                                            AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_all_end(AMPI_File fh, void *buf, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_ordered_begin(AMPI_File fh, void *buf, int count,
//                                               AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_File_read_ordered_end(AMPI_File fh, void *buf, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_ordered_begin(AMPI_File fh, void *buf, int count,
//                                                AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_File_write_ordered_end(AMPI_File fh, void *buf, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_type_extent(AMPI_File fh, AMPI_Datatype datatype,
//                                            AMPI_Aint *extent);
//DAMPI_DLL_PUBLIC  int AMPI_File_set_atomicity(AMPI_File fh, int flag);
//DAMPI_DLL_PUBLIC  int AMPI_File_get_atomicity(AMPI_File fh, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_File_sync(AMPI_File fh);
//#endif /* #if AMPI_PROVIDE_AMPI_FILE_INTERFACE */
DAMPI_DLL_PUBLIC  int AMPI_Finalize(void);
DAMPI_DLL_PUBLIC  int AMPI_Finalized(int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Free_mem(void *base);
//DAMPI_DLL_PUBLIC  int AMPI_Gather(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                              void *recvbuf, int recvcount, AMPI_Datatype recvtype,
//                              int root, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Gatherv(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                               void *recvbuf, int *recvcounts, int *displs,
//                               AMPI_Datatype recvtype, int root, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Get_address(void *location, AMPI_Aint *address);
//DAMPI_DLL_PUBLIC  int AMPI_Get_count(AMPI_Status *status, AMPI_Datatype datatype, int *count);
//DAMPI_DLL_PUBLIC  int AMPI_Get_elements(AMPI_Status *status, AMPI_Datatype datatype, int *count);
//DAMPI_DLL_PUBLIC  int AMPI_Get(void *origin_addr, int origin_count,
//                           AMPI_Datatype origin_datatype, int target_rank,
//                           AMPI_Aint target_disp, int target_count,
//                           AMPI_Datatype target_datatype, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Get_processor_name(char *name, int *resultlen);
//DAMPI_DLL_PUBLIC  int AMPI_Get_version(int *version, int *subversion);
//DAMPI_DLL_PUBLIC  int AMPI_Graph_create(AMPI_Comm comm_old, int nnodes, int *index,
//                                    int *edges, int reorder, AMPI_Comm *comm_graph);
//DAMPI_DLL_PUBLIC  int AMPI_Graph_get(AMPI_Comm comm, int maxindex, int maxedges,
//                                 int *index, int *edges);
//DAMPI_DLL_PUBLIC  int AMPI_Graph_map(AMPI_Comm comm, int nnodes, int *index, int *edges,
//                                 int *newrank);
//DAMPI_DLL_PUBLIC  int AMPI_Graph_neighbors_count(AMPI_Comm comm, int rank, int *nneighbors);
//DAMPI_DLL_PUBLIC  int AMPI_Graph_neighbors(AMPI_Comm comm, int rank, int maxneighbors,
//                                       int *neighbors);
//DAMPI_DLL_PUBLIC  int AMPI_Graphdims_get(AMPI_Comm comm, int *nnodes, int *nedges);
//DAMPI_DLL_PUBLIC  int AMPI_Grequest_complete(AMPI_Request request);
//DAMPI_DLL_PUBLIC  int AMPI_Grequest_start(AMPI_Grequest_query_function *query_fn,
//                                      AMPI_Grequest_free_function *free_fn,
//                                      AMPI_Grequest_cancel_function *cancel_fn,
//                                      void *extra_state, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Group_c2f(AMPI_Group group);
//DAMPI_DLL_PUBLIC  int AMPI_Group_compare(AMPI_Group group1, AMPI_Group group2, int *result);
//DAMPI_DLL_PUBLIC  int AMPI_Group_difference(AMPI_Group group1, AMPI_Group group2,
//                                        AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  int AMPI_Group_excl(AMPI_Group group, int n, int *ranks,
//                                  AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  AMPI_Group AMPI_Group_f2c(AMPI_Fint group);
//DAMPI_DLL_PUBLIC  int AMPI_Group_free(AMPI_Group *group);
//DAMPI_DLL_PUBLIC  int AMPI_Group_incl(AMPI_Group group, int n, int *ranks,
//                                  AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  int AMPI_Group_intersection(AMPI_Group group1, AMPI_Group group2,
//                                          AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  int AMPI_Group_range_excl(AMPI_Group group, int n, int ranges[][3],
//                                        AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  int AMPI_Group_range_incl(AMPI_Group group, int n, int ranges[][3],
//                                        AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  int AMPI_Group_rank(AMPI_Group group, int *rank);
//DAMPI_DLL_PUBLIC  int AMPI_Group_size(AMPI_Group group, int *size);
//DAMPI_DLL_PUBLIC  int AMPI_Group_translate_ranks(AMPI_Group group1, int n, int *ranks1,
//                                             AMPI_Group group2, int *ranks2);
//DAMPI_DLL_PUBLIC  int AMPI_Group_union(AMPI_Group group1, AMPI_Group group2,
//                                   AMPI_Group *newgroup);
//DAMPI_DLL_PUBLIC  int AMPI_Ibsend(void *buf, int count, AMPI_Datatype datatype, int dest,
//                              int tag, AMPI_Comm comm, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Info_c2f(AMPI_Info info);
//DAMPI_DLL_PUBLIC  int AMPI_Info_create(AMPI_Info *info);
//DAMPI_DLL_PUBLIC  int AMPI_Info_delete(AMPI_Info info, char *key);
//DAMPI_DLL_PUBLIC  int AMPI_Info_dup(AMPI_Info info, AMPI_Info *newinfo);
//DAMPI_DLL_PUBLIC  AMPI_Info AMPI_Info_f2c(AMPI_Fint info);
//DAMPI_DLL_PUBLIC  int AMPI_Info_free(AMPI_Info *info);
//DAMPI_DLL_PUBLIC  int AMPI_Info_get(AMPI_Info info, char *key, int valuelen,
//                                char *value, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Info_get_nkeys(AMPI_Info info, int *nkeys);
//DAMPI_DLL_PUBLIC  int AMPI_Info_get_nthkey(AMPI_Info info, int n, char *key);
//DAMPI_DLL_PUBLIC  int AMPI_Info_get_valuelen(AMPI_Info info, char *key, int *valuelen,
//                                         int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Info_set(AMPI_Info info, char *key, char *value);
DAMPI_DLL_PUBLIC  int AMPI_Init(int *argc, char ***argv);
DAMPI_DLL_PUBLIC  int AMPI_Initialized(int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Init_thread(int *argc, char ***argv, int required,
//                                   int *provided);
//DAMPI_DLL_PUBLIC  int AMPI_Intercomm_create(AMPI_Comm local_comm, int local_leader,
//                                        AMPI_Comm bridge_comm, int remote_leader,
//                                        int tag, AMPI_Comm *newintercomm);
//DAMPI_DLL_PUBLIC  int AMPI_Intercomm_merge(AMPI_Comm intercomm, int high,
//                                       AMPI_Comm *newintercomm);
//DAMPI_DLL_PUBLIC  int AMPI_Iprobe(int source, int tag, AMPI_Comm comm, int *flag,
//                              AMPI_Status *status);
DAMPI_DLL_PUBLIC  int AMPI_Irecv(void *buf, int count, AMPI_Datatype datatype, int source,
                             int tag, AMPI_Comm comm, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Irsend(void *buf, int count, AMPI_Datatype datatype, int dest,
//                              int tag, AMPI_Comm comm, AMPI_Request *request);
DAMPI_DLL_PUBLIC  int AMPI_Isend(void *buf, int count, AMPI_Datatype datatype, int dest,
                             int tag, AMPI_Comm comm, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Issend(void *buf, int count, AMPI_Datatype datatype, int dest,
//                              int tag, AMPI_Comm comm, AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Is_thread_main(int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Keyval_create(AMPI_Copy_function *copy_fn,
//                                     AMPI_Delete_function *delete_fn,
//                                     int *keyval, void *extra_state);
//DAMPI_DLL_PUBLIC  int AMPI_Keyval_free(int *keyval);
//DAMPI_DLL_PUBLIC  int AMPI_Lookup_name(char *service_name, AMPI_Info info, char *port_name);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Op_c2f(AMPI_Op op);
//DAMPI_DLL_PUBLIC  int AMPI_Op_create(AMPI_User_function *function, int commute, AMPI_Op *op);
//DAMPI_DLL_PUBLIC  int AMPI_Open_port(AMPI_Info info, char *port_name);
//DAMPI_DLL_PUBLIC  AMPI_Op AMPI_Op_f2c(AMPI_Fint op);
//DAMPI_DLL_PUBLIC  int AMPI_Op_free(AMPI_Op *op);
//DAMPI_DLL_PUBLIC  int AMPI_Pack_external(char *datarep, void *inbuf, int incount,
//                                     AMPI_Datatype datatype, void *outbuf,
//                                     AMPI_Aint outsize, AMPI_Aint *position);
//DAMPI_DLL_PUBLIC  int AMPI_Pack_external_size(char *datarep, int incount,
//                                          AMPI_Datatype datatype, AMPI_Aint *size);
//DAMPI_DLL_PUBLIC  int AMPI_Pack(void *inbuf, int incount, AMPI_Datatype datatype,
//                            void *outbuf, int outsize, int *position, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Pack_size(int incount, AMPI_Datatype datatype, AMPI_Comm comm,
//                                 int *size);
//DAMPI_DLL_PUBLIC  int AMPI_Pcontrol(const int level, ...);
//DAMPI_DLL_PUBLIC  int AMPI_Probe(int source, int tag, AMPI_Comm comm, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_Publish_name(char *service_name, AMPI_Info info,
//                                    char *port_name);
//DAMPI_DLL_PUBLIC  int AMPI_Put(void *origin_addr, int origin_count, AMPI_Datatype origin_datatype,
//                           int target_rank, AMPI_Aint target_disp, int target_count,
//                           AMPI_Datatype target_datatype, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Query_thread(int *provided);
//DAMPI_DLL_PUBLIC  int AMPI_Recv_init(void *buf, int count, AMPI_Datatype datatype, int source,
//                                 int tag, AMPI_Comm comm, AMPI_Request *request);
DAMPI_DLL_PUBLIC  int AMPI_Recv(void *buf, int count, AMPI_Datatype datatype, int source,
                            int tag, AMPI_Comm comm, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_Reduce(void *sendbuf, void *recvbuf, int count,
//                              AMPI_Datatype datatype, AMPI_Op op, int root, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
//                                      AMPI_Datatype datatype, AMPI_Op op, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Register_datarep(char *datarep,
//                                        AMPI_Datarep_conversion_function *read_conversion_fn,
//                                        AMPI_Datarep_conversion_function *write_conversion_fn,
//                                        AMPI_Datarep_extent_function *dtype_file_extent_fn,
//                                        void *extra_state);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Request_c2f(AMPI_Request request);
//DAMPI_DLL_PUBLIC  AMPI_Request AMPI_Request_f2c(AMPI_Fint request);
//DAMPI_DLL_PUBLIC  int AMPI_Request_free(AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Request_get_status(AMPI_Request request, int *flag,
//                                          AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_Rsend(void *ibuf, int count, AMPI_Datatype datatype, int dest,
//                             int tag, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Rsend_init(void *buf, int count, AMPI_Datatype datatype,
//                                  int dest, int tag, AMPI_Comm comm,
//                                  AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Scan(void *sendbuf, void *recvbuf, int count,
//                            AMPI_Datatype datatype, AMPI_Op op, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Scatter(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                               void *recvbuf, int recvcount, AMPI_Datatype recvtype,
//                               int root, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
//                                AMPI_Datatype sendtype, void *recvbuf, int recvcount,
//                                AMPI_Datatype recvtype, int root, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Send_init(void *buf, int count, AMPI_Datatype datatype,
//                                 int dest, int tag, AMPI_Comm comm,
//                                 AMPI_Request *request);
DAMPI_DLL_PUBLIC  int AMPI_Send(void *buf, int count, AMPI_Datatype datatype, int dest,
                            int tag, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Sendrecv(void *sendbuf, int sendcount, AMPI_Datatype sendtype,
//                                int dest, int sendtag, void *recvbuf, int recvcount,
//                                AMPI_Datatype recvtype, int source, int recvtag,
//                                AMPI_Comm comm,  AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_Sendrecv_replace(void * buf, int count, AMPI_Datatype datatype,
//                                        int dest, int sendtag, int source, int recvtag,
//                                        AMPI_Comm comm, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_Ssend_init(void *buf, int count, AMPI_Datatype datatype,
//                                  int dest, int tag, AMPI_Comm comm,
//                                  AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Ssend(void *buf, int count, AMPI_Datatype datatype, int dest,
//                             int tag, AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Start(AMPI_Request *request);
//DAMPI_DLL_PUBLIC  int AMPI_Startall(int count, AMPI_Request *array_of_requests);
//DAMPI_DLL_PUBLIC  int AMPI_Status_c2f(AMPI_Status *c_status, AMPI_Fint *f_status);
//DAMPI_DLL_PUBLIC  int AMPI_Status_f2c(AMPI_Fint *f_status, AMPI_Status *c_status);
//DAMPI_DLL_PUBLIC  int AMPI_Status_set_cancelled(AMPI_Status *status, int flag);
//DAMPI_DLL_PUBLIC  int AMPI_Status_set_elements(AMPI_Status *status, AMPI_Datatype datatype,
//                                           int count);
DAMPI_DLL_PUBLIC  int AMPI_Testall(int count, AMPI_Request array_of_requests[], int *flag,
                               AMPI_Status array_of_statuses[]);
DAMPI_DLL_PUBLIC  int AMPI_Testany(int count, AMPI_Request array_of_requests[], int *index,
                               int *flag, AMPI_Status *status);
DAMPI_DLL_PUBLIC  int AMPI_Test(AMPI_Request *request, int *flag, AMPI_Status *status);
//DAMPI_DLL_PUBLIC  int AMPI_Test_cancelled(AMPI_Status *status, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Testsome(int incount, AMPI_Request array_of_requests[],
//                                int *outcount, int array_of_indices[],
//                                AMPI_Status array_of_statuses[]);
//DAMPI_DLL_PUBLIC  int AMPI_Topo_test(AMPI_Comm comm, int *status);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Type_c2f(AMPI_Datatype datatype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_commit(AMPI_Datatype *type);
//DAMPI_DLL_PUBLIC  int AMPI_Type_contiguous(int count, AMPI_Datatype oldtype,
//                                       AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_darray(int size, int rank, int ndims,
//                                          int gsize_array[], int distrib_array[],
//                                          int darg_array[], int psize_array[],
//                                          int order, AMPI_Datatype oldtype,
//                                          AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_f90_complex(int p, int r, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_f90_integer(int r, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_f90_real(int p, int r, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_hindexed(int count, int array_of_blocklengths[],
//                                            AMPI_Aint array_of_displacements[],
//                                            AMPI_Datatype oldtype,
//                                            AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_hvector(int count, int blocklength, AMPI_Aint stride,
//                                           AMPI_Datatype oldtype,
//                                           AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_keyval(AMPI_Type_copy_attr_function *type_copy_attr_fn,
//                                          AMPI_Type_delete_attr_function *type_delete_attr_fn,
//                                          int *type_keyval, void *extra_state);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_indexed_block(int count, int blocklength,
//                                                 int array_of_displacements[],
//                                                 AMPI_Datatype oldtype,
//                                                 AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_struct(int count, int array_of_block_lengths[],
//                                          AMPI_Aint array_of_displacements[],
//                                          AMPI_Datatype array_of_types[],
//                                          AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_subarray(int ndims, int size_array[], int subsize_array[],
//                                            int start_array[], int order,
//                                            AMPI_Datatype oldtype, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_create_resized(AMPI_Datatype oldtype, AMPI_Aint lb,
//                                           AMPI_Aint extent, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_delete_attr(AMPI_Datatype type, int type_keyval);
//DAMPI_DLL_PUBLIC  int AMPI_Type_dup(AMPI_Datatype type, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_extent(AMPI_Datatype type, AMPI_Aint *extent);
//DAMPI_DLL_PUBLIC  int AMPI_Type_free(AMPI_Datatype *type);
//DAMPI_DLL_PUBLIC  int AMPI_Type_free_keyval(int *type_keyval);
//DAMPI_DLL_PUBLIC  AMPI_Datatype AMPI_Type_f2c(AMPI_Fint datatype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_get_attr(AMPI_Datatype type, int type_keyval,
//                                     void *attribute_val, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Type_get_contents(AMPI_Datatype mtype, int max_integers,
//                                         int max_addresses, int max_datatypes,
//                                         int array_of_integers[],
//                                         AMPI_Aint array_of_addresses[],
//                                         AMPI_Datatype array_of_datatypes[]);
//DAMPI_DLL_PUBLIC  int AMPI_Type_get_envelope(AMPI_Datatype type, int *num_integers,
//                                         int *num_addresses, int *num_datatypes,
//                                         int *combiner);
//DAMPI_DLL_PUBLIC  int AMPI_Type_get_extent(AMPI_Datatype type, AMPI_Aint *lb,
//                                       AMPI_Aint *extent);
//DAMPI_DLL_PUBLIC  int AMPI_Type_get_name(AMPI_Datatype type, char *type_name,
//                                     int *resultlen);
//DAMPI_DLL_PUBLIC  int AMPI_Type_get_true_extent(AMPI_Datatype datatype, AMPI_Aint *true_lb,
//                                            AMPI_Aint *true_extent);
//DAMPI_DLL_PUBLIC  int AMPI_Type_hindexed(int count, int array_of_blocklengths[],
//                                     AMPI_Aint array_of_displacements[],
//                                     AMPI_Datatype oldtype, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_hvector(int count, int blocklength, AMPI_Aint stride,
//                                    AMPI_Datatype oldtype, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_indexed(int count, int array_of_blocklengths[],
//                                    int array_of_displacements[],
//                                    AMPI_Datatype oldtype, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_lb(AMPI_Datatype type, AMPI_Aint *lb);
//DAMPI_DLL_PUBLIC  int AMPI_Type_match_size(int typeclass, int size, AMPI_Datatype *type);
//DAMPI_DLL_PUBLIC  int AMPI_Type_set_attr(AMPI_Datatype type, int type_keyval,
//                                     void *attr_val);
//DAMPI_DLL_PUBLIC  int AMPI_Type_set_name(AMPI_Datatype type, char *type_name);
//DAMPI_DLL_PUBLIC  int AMPI_Type_size(AMPI_Datatype type, int *size);
//DAMPI_DLL_PUBLIC  int AMPI_Type_struct(int count, int array_of_blocklengths[],
//                                   AMPI_Aint array_of_displacements[],
//                                   AMPI_Datatype array_of_types[],
//                                   AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Type_ub(AMPI_Datatype mtype, AMPI_Aint *ub);
//DAMPI_DLL_PUBLIC  int AMPI_Type_vector(int count, int blocklength, int stride,
//                                   AMPI_Datatype oldtype, AMPI_Datatype *newtype);
//DAMPI_DLL_PUBLIC  int AMPI_Unpack(void *inbuf, int insize, int *position,
//                              void *outbuf, int outcount, AMPI_Datatype datatype,
//                              AMPI_Comm comm);
//DAMPI_DLL_PUBLIC  int AMPI_Unpublish_name(char *service_name, AMPI_Info info, char *port_name);
//DAMPI_DLL_PUBLIC  int AMPI_Unpack_external (char *datarep, void *inbuf, AMPI_Aint insize,
//                                        AMPI_Aint *position, void *outbuf, int outcount,
//                                        AMPI_Datatype datatype);
DAMPI_DLL_PUBLIC  int AMPI_Waitall(int count, AMPI_Request *array_of_requests,
                               AMPI_Status *array_of_statuses);
DAMPI_DLL_PUBLIC  int AMPI_Waitany(int count, AMPI_Request *array_of_requests,
                               int *index, AMPI_Status *status);
DAMPI_DLL_PUBLIC  int AMPI_Wait(AMPI_Request *request, AMPI_Status *status);
DAMPI_DLL_PUBLIC  int AMPI_Waitsome(int incount, AMPI_Request *array_of_requests,
                                int *outcount, int *array_of_indices,
                                AMPI_Status *array_of_statuses);
//DAMPI_DLL_PUBLIC  AMPI_Fint AMPI_Win_c2f(AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_call_errhandler(AMPI_Win win, int errorcode);
//DAMPI_DLL_PUBLIC  int AMPI_Win_complete(AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_create(void *base, AMPI_Aint size, int disp_unit,
//                                  AMPI_Info info, AMPI_Comm comm, AMPI_Win *win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_create_errhandler(AMPI_Win_errhandler_fn *function,
//                                             AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Win_create_keyval(AMPI_Win_copy_attr_function *win_copy_attr_fn,
//                                         AMPI_Win_delete_attr_function *win_delete_attr_fn,
//                                         int *win_keyval, void *extra_state);
//DAMPI_DLL_PUBLIC  int AMPI_Win_delete_attr(AMPI_Win win, int win_keyval);
//DAMPI_DLL_PUBLIC  AMPI_Win AMPI_Win_f2c(AMPI_Fint win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_fence(int assert, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_free(AMPI_Win *win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_free_keyval(int *win_keyval);
//DAMPI_DLL_PUBLIC  int AMPI_Win_get_attr(AMPI_Win win, int win_keyval,
//                                    void *attribute_val, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Win_get_errhandler(AMPI_Win win, AMPI_Errhandler *errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Win_get_group(AMPI_Win win, AMPI_Group *group);
//DAMPI_DLL_PUBLIC  int AMPI_Win_get_name(AMPI_Win win, char *win_name, int *resultlen);
//DAMPI_DLL_PUBLIC  int AMPI_Win_lock(int lock_type, int rank, int assert, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_post(AMPI_Group group, int assert, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_set_attr(AMPI_Win win, int win_keyval, void *attribute_val);
//DAMPI_DLL_PUBLIC  int AMPI_Win_set_errhandler(AMPI_Win win, AMPI_Errhandler errhandler);
//DAMPI_DLL_PUBLIC  int AMPI_Win_set_name(AMPI_Win win, char *win_name);
//DAMPI_DLL_PUBLIC  int AMPI_Win_start(AMPI_Group group, int assert, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_test(AMPI_Win win, int *flag);
//DAMPI_DLL_PUBLIC  int AMPI_Win_unlock(int rank, AMPI_Win win);
//DAMPI_DLL_PUBLIC  int AMPI_Win_wait(AMPI_Win win);
//DAMPI_DLL_PUBLIC  double AMPI_Wtick(void);
//DAMPI_DLL_PUBLIC  double AMPI_Wtime(void);

}

#endif // AMPI_ABI_PROXY_H_GUARD
