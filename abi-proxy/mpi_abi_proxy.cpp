#include "mpi_abi_proxy.h"
#include <mpi.h>

#include <new>
#include <cassert>

#include <vector>

#if defined(MPI_PROXY_WITH_TRACE)
#include <iostream>
#define MTRACES(x) std::clog << x << '\n';
#else
#define MTRACES(x)
#endif

struct IAMPI_Comm
{
    MPI_Comm comm;
    IAMPI_Comm(MPI_Comm comm) : comm(comm) {}
};

struct IAMPI_Request
{
    MPI_Request request;
};

struct IAMPI_Status
{
    MPI_Status status;
};

AMPI_Request AMPI_Request_create()
{
    MTRACES("[O] Request_create");
    return new(std::nothrow) IAMPI_Request;
}


void AMPI_Request_free(AMPI_Request request)
{
    MTRACES("[O] Request_free");
    delete request;
}

AMPI_Status AMPI_Status_create()
{
    MTRACES("[O] Status_create");
    return new(std::nothrow) IAMPI_Status;
}


void AMPI_Status_free(AMPI_Status status)
{
    MTRACES("[O] Status_free");
    delete status;
}

const AMPI_Comm AMPI_COMM_WORLD = new(std::nothrow) IAMPI_Comm(MPI_COMM_WORLD);

class TypeConverter
{
public:
    TypeConverter()
    {
        types.resize(DATA_TYPES_COUNT);
        types.at(AMPI_CHAR) = MPI_CHAR;
        types.at(AMPI_SHORT) = MPI_SHORT;
        types.at(AMPI_INT) = MPI_INT;
        types.at(AMPI_LONG) = MPI_LONG;
        types.at(AMPI_UNSIGNED_CHAR) = MPI_UNSIGNED_CHAR;
        types.at(AMPI_UNSIGNED_SHORT) = MPI_UNSIGNED_SHORT;
        types.at(AMPI_UNSIGNED_LONG) = MPI_UNSIGNED_LONG;
        types.at(AMPI_UNSIGNED) = MPI_UNSIGNED;
        types.at(AMPI_FLOAT) = MPI_FLOAT;
        types.at(AMPI_DOUBLE) = MPI_DOUBLE;
        types.at(AMPI_LONG_DOUBLE) = MPI_LONG_DOUBLE;
        types.at(AMPI_LONG_LONG) = MPI_LONG_LONG;
        types.at(AMPI_UNSIGNED_LONG_LONG) = MPI_UNSIGNED_LONG_LONG;
    }

    MPI_Datatype convert(AMPI_Datatype type) {
        assert(type >=0 && type < DATA_TYPES_COUNT);
        return types[type];
    }

private:
    std::vector<MPI_Datatype> types;
    static const int DATA_TYPES_COUNT = 13;
};

static TypeConverter typeConverter;

MPI_Datatype toType(AMPI_Datatype type)
{
    return typeConverter.convert(type);
}

#define GENERATE_CASE(errvar) case A##errvar: return errvar;

int toErr(int err)
{
    switch (err) {
    GENERATE_CASE(MPI_SUCCESS)
    GENERATE_CASE(MPI_ERR_BUFFER)
    GENERATE_CASE(MPI_ERR_COUNT)
    GENERATE_CASE(MPI_ERR_TYPE)
    GENERATE_CASE(MPI_ERR_TAG)
    GENERATE_CASE(MPI_ERR_COMM)
    GENERATE_CASE(MPI_ERR_RANK)
    GENERATE_CASE(MPI_ERR_REQUEST)
    GENERATE_CASE(MPI_ERR_ROOT)
    GENERATE_CASE(MPI_ERR_GROUP)
    GENERATE_CASE(MPI_ERR_OP)
    GENERATE_CASE(MPI_ERR_TOPOLOGY)
    GENERATE_CASE(MPI_ERR_DIMS)
    GENERATE_CASE(MPI_ERR_ARG)
    GENERATE_CASE(MPI_ERR_UNKNOWN)
    GENERATE_CASE(MPI_ERR_TRUNCATE)
    GENERATE_CASE(MPI_ERR_OTHER)
    GENERATE_CASE(MPI_ERR_INTERN)
    GENERATE_CASE(MPI_ERR_IN_STATUS)
    GENERATE_CASE(MPI_ERR_PENDING)
    GENERATE_CASE(MPI_ERR_ACCESS)
    GENERATE_CASE(MPI_ERR_AMODE)
    GENERATE_CASE(MPI_ERR_ASSERT)
    GENERATE_CASE(MPI_ERR_BAD_FILE)
    GENERATE_CASE(MPI_ERR_BASE)
    GENERATE_CASE(MPI_ERR_CONVERSION)
    GENERATE_CASE(MPI_ERR_DISP)
    GENERATE_CASE(MPI_ERR_DUP_DATAREP)
    GENERATE_CASE(MPI_ERR_FILE_EXISTS)
    GENERATE_CASE(MPI_ERR_FILE_IN_USE)
    GENERATE_CASE(MPI_ERR_FILE)
    GENERATE_CASE(MPI_ERR_INFO_KEY)
    GENERATE_CASE(MPI_ERR_INFO_NOKEY)
    GENERATE_CASE(MPI_ERR_INFO_VALUE)
    GENERATE_CASE(MPI_ERR_INFO)
    GENERATE_CASE(MPI_ERR_IO)
    GENERATE_CASE(MPI_ERR_KEYVAL)
    GENERATE_CASE(MPI_ERR_LOCKTYPE)
    GENERATE_CASE(MPI_ERR_NAME)
    GENERATE_CASE(MPI_ERR_NO_MEM)
    GENERATE_CASE(MPI_ERR_NOT_SAME)
    GENERATE_CASE(MPI_ERR_NO_SPACE)
    GENERATE_CASE(MPI_ERR_NO_SUCH_FILE)
    GENERATE_CASE(MPI_ERR_PORT)
    GENERATE_CASE(MPI_ERR_QUOTA)
    GENERATE_CASE(MPI_ERR_READ_ONLY)
    GENERATE_CASE(MPI_ERR_RMA_CONFLICT)
    GENERATE_CASE(MPI_ERR_RMA_SYNC)
    GENERATE_CASE(MPI_ERR_SERVICE)
    GENERATE_CASE(MPI_ERR_SIZE)
    GENERATE_CASE(MPI_ERR_SPAWN)
    GENERATE_CASE(MPI_ERR_UNSUPPORTED_DATAREP)
    GENERATE_CASE(MPI_ERR_UNSUPPORTED_OPERATION)
    GENERATE_CASE(MPI_ERR_WIN)
    GENERATE_CASE(MPI_ERR_LASTCODE)
    GENERATE_CASE(MPI_ERR_SYSRESOURCE)
    }
    return MPI_ERR_UNKNOWN;
}

int AMPI_Abort(AMPI_Comm comm, int errorcode)
{
    MTRACES("[O] Abort");
    assert(comm);
    return toErr(MPI_Abort(comm->comm, errorcode));
}


int AMPI_Barrier(AMPI_Comm comm)
{
    MTRACES("[O] Barrier");
    assert(comm);
    return toErr(MPI_Barrier(comm->comm));
}


int AMPI_Cancel(AMPI_Request *request)
{
    MTRACES("[O] Cancel");
    assert(request);
    assert(*request);
    return toErr(MPI_Cancel(&((*request)->request)));
}


int AMPI_Finalize()
{
    MTRACES("[O] Finalize");
    return toErr(MPI_Finalize());
}


int AMPI_Finalized(int *flag)
{
    MTRACES("[O] Finalized");
    assert(flag);
    return toErr(AMPI_Finalized(flag));
}


int AMPI_Init(int *argc, char ***argv)
{
    MTRACES("[O] Init");
    return toErr(MPI_Init(argc, argv));
}


int AMPI_Initialized(int *flag)
{
    MTRACES("[O] Initialized");
    return toErr(MPI_Initialized(flag));
}


int AMPI_Irecv(void *buf, int count, AMPI_Datatype datatype, int source, int tag, AMPI_Comm comm, AMPI_Request *request)
{
    MTRACES("[O] Irecv");
    assert(buf);
    assert(comm);
    assert(request);
    assert(*request);
    return toErr(MPI_Irecv(buf, count, toType(datatype), source, tag, comm->comm, &((*request)->request)));
}


int AMPI_Isend(void *buf, int count, AMPI_Datatype datatype, int dest, int tag, AMPI_Comm comm, AMPI_Request *request)
{
    MTRACES("[O] Isend");
    assert(buf);
    assert(comm);
    assert(request);
    assert(*request);
    return toErr(MPI_Isend(buf, count, toType(datatype), dest, tag, comm->comm, &((*request)->request)));
}


int AMPI_Recv(void *buf, int count, AMPI_Datatype datatype, int source, int tag, AMPI_Comm comm, AMPI_Status *status)
{
    MTRACES("[O] Recv");
    assert(buf);
    assert(comm);
    assert(status);
    assert(*status);
    return toErr(MPI_Recv(buf, count, toType(datatype), source, tag, comm->comm, &((*status)->status)));
}


int AMPI_Send(void *buf, int count, AMPI_Datatype datatype, int dest, int tag, AMPI_Comm comm)
{
    MTRACES("[O] Send");
    assert(buf);
    assert(comm);
    return toErr(MPI_Send(buf, count, toType(datatype), dest, tag, comm->comm));
}


int AMPI_Testall(int count, AMPI_Request array_of_requests[], int *flag, AMPI_Status array_of_statuses[])
{
    MTRACES("[O] Testall");
    assert(count >= 0 );
    assert(flag);
    assert(array_of_requests);
    assert(array_of_statuses);
    std::vector<MPI_Request> reqs(count);
    std::vector<MPI_Status> statuses(count);
    for (int i = 0; i < count; ++i)
    {
        assert(array_of_requests[i]);
        reqs[i] = array_of_requests[i]->request;
        assert(array_of_statuses[i]);
        statuses[i] = array_of_statuses[i]->status;
    }
    int res = MPI_Testall(count, reqs.data(), flag, statuses.data());
    for (int i = 0; i < count; ++i)
    {
        array_of_statuses[i]->status = statuses[i];
    }
    return toErr(res);
}


int AMPI_Testany(int count, AMPI_Request array_of_requests[], int *index, int *flag, AMPI_Status *status)
{
    MTRACES("[O] Testany");
    assert(count >= 0 );
    assert(index);
    assert(flag);
    assert(array_of_requests);
    assert(status);
    assert(*status);
    std::vector<MPI_Request> reqs(count);
    for (int i = 0; i < count; ++i)
    {
        assert(array_of_requests[i]);
        reqs[i] = array_of_requests[i]->request;
    }
    return toErr(MPI_Testany(count, reqs.data(), index, flag, &((*status)->status)));
}


int AMPI_Test(AMPI_Request *request, int *flag, AMPI_Status *status)
{
    MTRACES("[O] Test");
    assert(request);
    assert(*request);
    assert(flag);
    assert(status);
    assert(*status);
    return toErr(MPI_Test(&((*request)->request), flag, &((*status)->status)));
}


int AMPI_Waitall(int count, AMPI_Request *array_of_requests, AMPI_Status *array_of_statuses)
{
    MTRACES("[O] Waitall");
    assert(count >= 0 );
    assert(array_of_requests);
    assert(array_of_statuses);
    std::vector<MPI_Request> reqs(count);
    std::vector<MPI_Status> statuses(count);
    for (int i = 0; i < count; ++i)
    {
        assert(array_of_requests[i]);
        reqs[i] = array_of_requests[i]->request;
        assert(array_of_statuses[i]);
        statuses[i] = array_of_statuses[i]->status;
    }
    int res = MPI_Waitall(count, reqs.data(), statuses.data());
    for (int i = 0; i < count; ++i)
    {
        array_of_statuses[i]->status = statuses[i];
    }
    return toErr(res);
}


int AMPI_Waitany(int count, AMPI_Request *array_of_requests, int *index, AMPI_Status *status)
{
    MTRACES("[O] Waitany");
    assert(count >= 0 );
    assert(index);
    assert(array_of_requests);
    assert(status);
    assert(*status);
    std::vector<MPI_Request> reqs(count);
    for (int i = 0; i < count; ++i)
    {
        assert(array_of_requests[i]);
        reqs[i] = array_of_requests[i]->request;
    }
    return toErr(MPI_Waitany(count, reqs.data(), index, &((*status)->status)));
}


int AMPI_Wait(AMPI_Request *request, AMPI_Status *status)
{
    MTRACES("[O] Wait");
    assert(request);
    assert(*request);
    assert(status);
    assert(*status);
    return toErr(MPI_Wait(&((*request)->request), &((*status)->status)));
}


int AMPI_Waitsome(int incount, AMPI_Request *array_of_requests, int *outcount, int *array_of_indices, AMPI_Status *array_of_statuses)
{
    MTRACES("[O] Waitsome");
    assert(incount >= 0 );
    assert(array_of_requests);
    assert(outcount);
    assert(array_of_indices);
    assert(array_of_statuses);
    std::vector<MPI_Request> reqs(incount);
    std::vector<MPI_Status> statuses(incount);
    for (int i = 0; i < incount; ++i)
    {
        assert(array_of_requests[i]);
        reqs[i] = array_of_requests[i]->request;
        assert(array_of_statuses[i]);
        statuses[i] = array_of_statuses[i]->status;
    }
    int res = MPI_Waitsome(incount, reqs.data(), outcount, array_of_indices, statuses.data());
    for (int i = 0; i < incount; ++i)
    {
        array_of_statuses[i]->status = statuses[i];
    }
    return toErr(res);
}


int AMPI_Comm_rank(AMPI_Comm comm, int *rank)
{
    MTRACES("[O] Comm_rank");
    assert(comm);
    assert(rank);
    return MPI_Comm_rank(comm->comm, rank);
}


int AMPI_Comm_size(AMPI_Comm comm, int *size)
{
    MTRACES("[O] Comm_size");
    assert(comm);
    assert(size);
    return MPI_Comm_size(comm->comm, size);
}
