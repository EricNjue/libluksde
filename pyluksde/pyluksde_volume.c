/*
 * Python object wrapper of libluksde_volume_t
 *
 * Copyright (C) 2013-2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyluksde_error.h"
#include "pyluksde_file_object_io_handle.h"
#include "pyluksde_integer.h"
#include "pyluksde_libbfio.h"
#include "pyluksde_libcerror.h"
#include "pyluksde_libluksde.h"
#include "pyluksde_python.h"
#include "pyluksde_unused.h"
#include "pyluksde_volume.h"

#if !defined( LIBLUKSDE_HAVE_BFIO )

LIBLUKSDE_EXTERN \
int libluksde_volume_open_file_io_handle(
     libluksde_volume_t *volume,
     libbfio_handle_t *file_io_handle,
     int access_flags,
     libluksde_error_t **error );

#endif /* !defined( LIBLUKSDE_HAVE_BFIO ) */

PyMethodDef pyluksde_volume_object_methods[] = {

	{ "signal_abort",
	  (PyCFunction) pyluksde_volume_signal_abort,
	  METH_NOARGS,
	  "signal_abort() -> None\n"
	  "\n"
	  "Signals the volume to abort the current activity." },

	{ "open",
	  (PyCFunction) pyluksde_volume_open,
	  METH_VARARGS | METH_KEYWORDS,
	  "open(filename, mode='r') -> None\n"
	  "\n"
	  "Opens a volume." },

	{ "open_file_object",
	  (PyCFunction) pyluksde_volume_open_file_object,
	  METH_VARARGS | METH_KEYWORDS,
	  "open_file_object(file_object, mode='r') -> None\n"
	  "\n"
	  "Opens a volume using a file-like object." },

	{ "close",
	  (PyCFunction) pyluksde_volume_close,
	  METH_NOARGS,
	  "close() -> None\n"
	  "\n"
	  "Closes a volume." },

	{ "read_buffer",
	  (PyCFunction) pyluksde_volume_read_buffer,
	  METH_VARARGS | METH_KEYWORDS,
	  "read_buffer(size) -> Binary string or None\n"
	  "\n"
	  "Reads a buffer of data." },

	{ "read_buffer_at_offset",
	  (PyCFunction) pyluksde_volume_read_buffer_at_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "read_buffer_at_offset(size, offset) -> Binary string or None\n"
	  "\n"
	  "Reads a buffer of data at a specific offset." },

	{ "seek_offset",
	  (PyCFunction) pyluksde_volume_seek_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "seek_offset(offset, whence) -> None\n"
	  "\n"
	  "Seeks an offset within the data." },

	{ "get_offset",
	  (PyCFunction) pyluksde_volume_get_offset,
	  METH_NOARGS,
	  "get_offset() -> Integer or None\n"
	  "\n"
	  "Retrieves the current offset within the data." },

	{ "read",
	  (PyCFunction) pyluksde_volume_read_buffer,
	  METH_VARARGS | METH_KEYWORDS,
	  "read(size) -> String\n"
	  "\n"
	  "Reads a buffer of data." },

	{ "seek",
	  (PyCFunction) pyluksde_volume_seek_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "seek(offset, whence) -> None\n"
	  "\n"
	  "Seeks an offset within the data." },

	{ "tell",
	  (PyCFunction) pyluksde_volume_get_offset,
	  METH_NOARGS,
	  "tell() -> Integer\n"
	  "\n"
	  "Retrieves the current offset within the data." },

	{ "get_size",
	  (PyCFunction) pyluksde_volume_get_size,
	  METH_NOARGS,
	  "get_size() -> Integer or None\n"
	  "\n"
	  "Retrieves the size." },

	{ "get_encryption_method",
	  (PyCFunction) pyluksde_volume_get_encryption_method,
	  METH_NOARGS,
	  "get_encryption_method() -> Integer or None\n"
	  "\n"
	  "Retrieves the encryption method." },

	{ "set_password",
	  (PyCFunction) pyluksde_volume_set_password,
	  METH_VARARGS | METH_KEYWORDS,
	  "set_password(password) -> None\n"
	  "\n"
	  "Sets the password." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyluksde_volume_object_get_set_definitions[] = {

	{ "size",
	  (getter) pyluksde_volume_get_size,
	  (setter) 0,
	  "The size.",
	  NULL },

	{ "encryption_method",
	  (getter) pyluksde_volume_get_encryption_method,
	  (setter) 0,
	  "The encryption method.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyluksde_volume_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyluksde.volume",
	/* tp_basicsize */
	sizeof( pyluksde_volume_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyluksde_volume_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyluksde volume object (wraps libluksde_volume_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyluksde_volume_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyluksde_volume_object_get_set_definitions,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyluksde_volume_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new volume object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_new(
           void )
{
	pyluksde_volume_t *pyluksde_volume = NULL;
	static char *function              = "pyluksde_volume_new";

	pyluksde_volume = PyObject_New(
	                   struct pyluksde_volume,
	                   &pyluksde_volume_type_object );

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize volume.",
		 function );

		goto on_error;
	}
	if( pyluksde_volume_init(
	     pyluksde_volume ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize volume.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyluksde_volume );

on_error:
	if( pyluksde_volume != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyluksde_volume );
	}
	return( NULL );
}

/* Creates a new volume object and opens it
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_new_open(
           PyObject *self PYLUKSDE_ATTRIBUTE_UNUSED,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *pyluksde_volume = NULL;

	PYLUKSDE_UNREFERENCED_PARAMETER( self )

	pyluksde_volume = pyluksde_volume_new();

	pyluksde_volume_open(
	 (pyluksde_volume_t *) pyluksde_volume,
	 arguments,
	 keywords );

	return( pyluksde_volume );
}

/* Creates a new volume object and opens it using a file-like object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_new_open_file_object(
           PyObject *self PYLUKSDE_ATTRIBUTE_UNUSED,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *pyluksde_volume = NULL;

	PYLUKSDE_UNREFERENCED_PARAMETER( self )

	pyluksde_volume = pyluksde_volume_new();

	pyluksde_volume_open_file_object(
	 (pyluksde_volume_t *) pyluksde_volume,
	 arguments,
	 keywords );

	return( pyluksde_volume );
}

/* Intializes a volume object
 * Returns 0 if successful or -1 on error
 */
int pyluksde_volume_init(
     pyluksde_volume_t *pyluksde_volume )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyluksde_volume_init";

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	pyluksde_volume->volume         = NULL;
	pyluksde_volume->file_io_handle = NULL;

	if( libluksde_volume_initialize(
	     &( pyluksde_volume->volume ),
	     &error ) != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to initialize volume.",
		 function );

		libcerror_error_free(
		 &error );

		return( -1 );
	}
	return( 0 );
}

/* Frees a volume object
 */
void pyluksde_volume_free(
      pyluksde_volume_t *pyluksde_volume )
{
	struct _typeobject *ob_type = NULL;
	libcerror_error_t *error    = NULL;
	static char *function       = "pyluksde_volume_free";
	int result                  = 0;

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return;
	}
	if( pyluksde_volume->volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume - missing libluksde volume.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyluksde_volume );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_free(
	          &( pyluksde_volume->volume ),
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to free libluksde volume.",
		 function );

		libcerror_error_free(
		 &error );
	}
	ob_type->tp_free(
	 (PyObject*) pyluksde_volume );
}

/* Signals the volume to abort the current activity
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_signal_abort(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments PYLUKSDE_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyluksde_volume_signal_abort";
	int result               = 0;

	PYLUKSDE_UNREFERENCED_PARAMETER( arguments )

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_signal_abort(
	          pyluksde_volume->volume,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to signal abort.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Opens a volume
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_open(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *string_object      = NULL;
	libcerror_error_t *error     = NULL;
	const char *filename_narrow  = NULL;
	static char *function        = "pyluksde_volume_open";
	static char *keyword_list[]  = { "filename", "mode", NULL };
	char *mode                   = NULL;
	int result                   = 0;

#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	const wchar_t *filename_wide = NULL;
#else
	PyObject *utf8_string_object = NULL;
#endif

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	/* Note that PyArg_ParseTupleAndKeywords with "s" will force Unicode strings to be converted to narrow character string.
	 * On Windows the narrow character strings contains an extended ASCII string with a codepage. Hence we get a conversion
	 * exception. This will also fail if the default encoding is not set correctly. We cannot use "u" here either since that
	 * does not allow us to pass non Unicode string objects and Python (at least 2.7) does not seems to automatically upcast them.
	 */
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "O|s",
	     keyword_list,
	     &string_object,
	     &mode ) == 0 )
	{
		return( NULL );
	}
	if( ( mode != NULL )
	 && ( mode[ 0 ] != 'r' ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: unsupported mode: %s.",
		 function,
		 mode );

		return( NULL );
	}
	PyErr_Clear();

	result = PyObject_IsInstance(
	          string_object,
	          (PyObject *) &PyUnicode_Type );

	if( result == -1 )
	{
		pyluksde_error_fetch_and_raise(
		 PyExc_RuntimeError,
		 "%s: unable to determine if string object is of type unicode.",
		 function );

		return( NULL );
	}
	else if( result != 0 )
	{
		PyErr_Clear();

#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
		filename_wide = (wchar_t *) PyUnicode_AsUnicode(
		                             string_object );
		Py_BEGIN_ALLOW_THREADS

		result = libluksde_volume_open_wide(
		          pyluksde_volume->volume,
		          filename_wide,
		          LIBLUKSDE_OPEN_READ,
		          &error );

		Py_END_ALLOW_THREADS
#else
		utf8_string_object = PyUnicode_AsUTF8String(
		                      string_object );

		if( utf8_string_object == NULL )
		{
			pyluksde_error_fetch_and_raise(
			 PyExc_RuntimeError,
			 "%s: unable to convert unicode string to UTF-8.",
			 function );

			return( NULL );
		}
#if PY_MAJOR_VERSION >= 3
		filename_narrow = PyBytes_AsString(
		                   utf8_string_object );
#else
		filename_narrow = PyString_AsString(
		                   utf8_string_object );
#endif
		Py_BEGIN_ALLOW_THREADS

		result = libluksde_volume_open(
		          pyluksde_volume->volume,
		          filename_narrow,
		          LIBLUKSDE_OPEN_READ,
		          &error );

		Py_END_ALLOW_THREADS

		Py_DecRef(
		 utf8_string_object );
#endif
		if( result != 1 )
		{
			pyluksde_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to open volume.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	PyErr_Clear();

#if PY_MAJOR_VERSION >= 3
	result = PyObject_IsInstance(
	          string_object,
	          (PyObject *) &PyBytes_Type );
#else
	result = PyObject_IsInstance(
	          string_object,
	          (PyObject *) &PyString_Type );
#endif
	if( result == -1 )
	{
		pyluksde_error_fetch_and_raise(
		 PyExc_RuntimeError,
		 "%s: unable to determine if string object is of type string.",
		 function );

		return( NULL );
	}
	else if( result != 0 )
	{
		PyErr_Clear();

#if PY_MAJOR_VERSION >= 3
		filename_narrow = PyBytes_AsString(
		                   string_object );
#else
		filename_narrow = PyString_AsString(
		                   string_object );
#endif
		Py_BEGIN_ALLOW_THREADS

		result = libluksde_volume_open(
		          pyluksde_volume->volume,
		          filename_narrow,
		          LIBLUKSDE_OPEN_READ,
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyluksde_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to open volume.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	PyErr_Format(
	 PyExc_TypeError,
	 "%s: unsupported string object type.",
	 function );

	return( NULL );
}

/* Opens a volume using a file-like object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_open_file_object(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *file_object       = NULL;
	libcerror_error_t *error    = NULL;
	static char *function       = "pyluksde_volume_open_file_object";
	static char *keyword_list[] = { "file_object", "mode", NULL };
	char *mode                  = NULL;
	int result                  = 0;

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "O|s",
	     keyword_list,
	     &file_object,
	     &mode ) == 0 )
	{
		return( NULL );
	}
	if( ( mode != NULL )
	 && ( mode[ 0 ] != 'r' ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: unsupported mode: %s.",
		 function,
		 mode );

		return( NULL );
	}
	if( pyluksde_volume->file_io_handle != NULL )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: invalid volume - file IO handle already set.",
		 function );

		goto on_error;
	}
	if( pyluksde_file_object_initialize(
	     &( pyluksde_volume->file_io_handle ),
	     file_object,
	     &error ) != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_MemoryError,
		 "%s: unable to initialize file IO handle.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_open_file_io_handle(
	          pyluksde_volume->volume,
	          pyluksde_volume->file_io_handle,
	          LIBLUKSDE_OPEN_READ,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to open volume.",
		 function );

		libcerror_error_free(
		 &error );

		goto on_error;
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );

on_error:
	if( pyluksde_volume->file_io_handle != NULL )
	{
		libbfio_handle_free(
		 &( pyluksde_volume->file_io_handle ),
		 NULL );
	}
	return( NULL );
}

/* Closes a volume
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_close(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments PYLUKSDE_ATTRIBUTE_UNUSED )
{
	libcerror_error_t *error = NULL;
	static char *function    = "pyluksde_volume_close";
	int result               = 0;

	PYLUKSDE_UNREFERENCED_PARAMETER( arguments )

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_close(
	          pyluksde_volume->volume,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 0 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to close volume.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	if( pyluksde_volume->file_io_handle != NULL )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libbfio_handle_free(
		          &( pyluksde_volume->file_io_handle ),
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyluksde_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to free libbfio file IO handle.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Reads data at the current offset into a buffer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_read_buffer(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *integer_object    = NULL;
	PyObject *string_object     = NULL;
	libcerror_error_t *error    = NULL;
	char *buffer                = NULL;
	static char *function       = "pyluksde_volume_read_buffer";
	static char *keyword_list[] = { "size", NULL };
	ssize_t read_count          = 0;
	int64_t read_size           = 0;
	int result                  = 0;

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "|O",
	     keyword_list,
	     &integer_object ) == 0 )
	{
		return( NULL );
	}
	if( integer_object == NULL )
	{
		result = 0;
	}
	else
	{
		result = PyObject_IsInstance(
		          integer_object,
		          (PyObject *) &PyLong_Type );

		if( result == -1 )
		{
			pyluksde_error_fetch_and_raise(
			 PyExc_RuntimeError,
			 "%s: unable to determine if integer object is of type long.",
			 function );

			return( NULL );
		}
#if PY_MAJOR_VERSION < 3
		else if( result == 0 )
		{
			PyErr_Clear();

			result = PyObject_IsInstance(
			          integer_object,
			          (PyObject *) &PyInt_Type );

			if( result == -1 )
			{
				pyluksde_error_fetch_and_raise(
				 PyExc_RuntimeError,
				 "%s: unable to determine if integer object is of type int.",
				 function );

				return( NULL );
			}
		}
#endif
	}
	if( result != 0 )
	{
		if( pyluksde_integer_signed_copy_to_64bit(
		     integer_object,
		     &read_size,
		     &error ) != 1 )
		{
			pyluksde_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to convert integer object into read size.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	else if( ( integer_object == NULL )
	      || ( integer_object == Py_None ) )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libluksde_volume_get_size(
		          pyluksde_volume->volume,
		          (size64_t *) &read_size,
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyluksde_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to retrieve size.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	else
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: unsupported integer object type.",
		 function );

		return( NULL );
	}
	if( read_size == 0 )
	{
#if PY_MAJOR_VERSION >= 3
		string_object = PyBytes_FromString(
		                 "" );
#else
		string_object = PyString_FromString(
		                 "" );
#endif
		return( string_object );
	}
	if( read_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid read size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( ( read_size > (int64_t) INT_MAX )
	 || ( read_size > (int64_t) SSIZE_MAX ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value exceeds maximum.",
		 function );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	string_object = PyBytes_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyBytes_AsString(
	          string_object );
#else
	/* Note that a size of 0 is not supported
	 */
	string_object = PyString_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyString_AsString(
	          string_object );
#endif
	Py_BEGIN_ALLOW_THREADS

	read_count = libluksde_volume_read_buffer(
	              pyluksde_volume->volume,
	              (uint8_t *) buffer,
	              (size_t) read_size,
	              &error );

	Py_END_ALLOW_THREADS

	if( read_count == -1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to read data.",
		 function );

		libcerror_error_free(
		 &error );

		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	/* Need to resize the string here in case read_size was not fully read.
	 */
#if PY_MAJOR_VERSION >= 3
	if( _PyBytes_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#else
	if( _PyString_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#endif
	{
		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	return( string_object );
}

/* Reads data at a specific offset into a buffer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_read_buffer_at_offset(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *integer_object    = NULL;
	PyObject *string_object     = NULL;
	libcerror_error_t *error    = NULL;
	char *buffer                = NULL;
	static char *function       = "pyluksde_volume_read_buffer_at_offset";
	static char *keyword_list[] = { "size", "offset", NULL };
	ssize_t read_count          = 0;
	off64_t read_offset         = 0;
	int64_t read_size           = 0;
	int result                  = 0;

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "OL",
	     keyword_list,
	     &integer_object,
	     &read_offset ) == 0 )
	{
		return( NULL );
	}
	result = PyObject_IsInstance(
	          integer_object,
	          (PyObject *) &PyLong_Type );

	if( result == -1 )
	{
		pyluksde_error_fetch_and_raise(
		 PyExc_RuntimeError,
		 "%s: unable to determine if integer object is of type long.",
		 function );

		return( NULL );
	}
#if PY_MAJOR_VERSION < 3
	else if( result == 0 )
	{
		PyErr_Clear();

		result = PyObject_IsInstance(
		          integer_object,
		          (PyObject *) &PyInt_Type );

		if( result == -1 )
		{
			pyluksde_error_fetch_and_raise(
			 PyExc_RuntimeError,
			 "%s: unable to determine if integer object is of type int.",
			 function );

			return( NULL );
		}
	}
#endif
	if( result != 0 )
	{
		if( pyluksde_integer_signed_copy_to_64bit(
		     integer_object,
		     &read_size,
		     &error ) != 1 )
		{
			pyluksde_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to convert integer object into read size.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	else
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: unsupported integer object type.",
		 function );

		return( NULL );
	}
	if( read_size == 0 )
	{
#if PY_MAJOR_VERSION >= 3
		string_object = PyBytes_FromString(
		                 "" );
#else
		string_object = PyString_FromString(
		                 "" );
#endif
		return( string_object );
	}
	if( read_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid read size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( ( read_size > (int64_t) INT_MAX )
	 || ( read_size > (int64_t) SSIZE_MAX ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value exceeds maximum.",
		 function );

		return( NULL );
	}
	if( read_offset < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid read offset value less than zero.",
		 function );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	string_object = PyBytes_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyBytes_AsString(
	          string_object );
#else
	/* Note that a size of 0 is not supported
	 */
	string_object = PyString_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyString_AsString(
	          string_object );
#endif
	Py_BEGIN_ALLOW_THREADS

	read_count = libluksde_volume_read_buffer_at_offset(
	              pyluksde_volume->volume,
	              (uint8_t *) buffer,
	              (size_t) read_size,
	              (off64_t) read_offset,
	              &error );

	Py_END_ALLOW_THREADS

	if( read_count == -1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to read data.",
		 function );

		libcerror_error_free(
		 &error );

		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	/* Need to resize the string here in case read_size was not fully read.
	 */
#if PY_MAJOR_VERSION >= 3
	if( _PyBytes_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#else
	if( _PyString_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#endif
	{
		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	return( string_object );
}

/* Seeks a certain offset
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_seek_offset(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments,
           PyObject *keywords )
{
	libcerror_error_t *error    = NULL;
	static char *function       = "pyluksde_volume_seek_offset";
	static char *keyword_list[] = { "offset", "whence", NULL };
	off64_t offset              = 0;
	int whence                  = 0;

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "L|i",
	     keyword_list,
	     &offset,
	     &whence ) == 0 )
	{
		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	offset = libluksde_volume_seek_offset(
	          pyluksde_volume->volume,
	          offset,
	          whence,
	          &error );

	Py_END_ALLOW_THREADS

 	if( offset == -1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to seek offset.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Retrieves the offset
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_get_offset(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments PYLUKSDE_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyluksde_volume_get_offset";
	off64_t offset           = 0;
	int result               = 0;

	PYLUKSDE_UNREFERENCED_PARAMETER( arguments )

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_get_offset(
	          pyluksde_volume->volume,
	          &offset,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve offset.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	integer_object = pyluksde_integer_signed_new_from_64bit(
	                  (int64_t) offset );

	return( integer_object );
}

/* Retrieves the size
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_get_size(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments PYLUKSDE_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyluksde_volume_get_size";
	size64_t size            = 0;
	int result               = 0;

	PYLUKSDE_UNREFERENCED_PARAMETER( arguments )

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_get_size(
	          pyluksde_volume->volume,
	          &size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: failed to retrieve size.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyluksde_integer_unsigned_new_from_64bit(
	                  (uint64_t) size );

	return( integer_object );
}

/* Retrieves the encryption method
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_get_encryption_method(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments PYLUKSDE_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object     = NULL;
	libcerror_error_t *error     = NULL;
	static char *function        = "pyluksde_volume_get_encryption_method";
	int encryption_method        = 0;
	int encryption_chaining_mode = 0;
	int result                   = 0;

	PYLUKSDE_UNREFERENCED_PARAMETER( arguments )

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_get_encryption_method(
	          pyluksde_volume->volume,
	          &encryption_method,
	          &encryption_chaining_mode,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve encryption method.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) encryption_method );
#else
	integer_object = PyInt_FromLong(
	                  (long) encryption_method );
#endif
	return( integer_object );
}

/* Sets the password
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_volume_set_password(
           pyluksde_volume_t *pyluksde_volume,
           PyObject *arguments,
           PyObject *keywords )
{
	libcerror_error_t *error    = NULL;
	static char *function       = "pyluksde_volume_set_password";
	static char *keyword_list[] = { "password", NULL };
	char *utf8_string           = NULL;
	size_t utf8_string_length   = 0;
	int result                  = 0;

	if( pyluksde_volume == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid volume.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "s",
	     keyword_list,
	     &utf8_string ) == 0 )
	{
		return( NULL );
	}
	if( utf8_string == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid password.",
		 function );

		return( NULL );
	}
	utf8_string_length = narrow_string_length(
	                      utf8_string );

	Py_BEGIN_ALLOW_THREADS

	result = libluksde_volume_set_utf8_password(
	          pyluksde_volume->volume,
	          (uint8_t *) utf8_string,
	          utf8_string_length,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyluksde_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to set password.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

