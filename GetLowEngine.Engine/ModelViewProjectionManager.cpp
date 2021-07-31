#include "pch.h"
#include "ModelViewProjectionManager.h"


/**
 * @brief Construct a new Model View Projection Manager:: Model View Projection Manager object
 *  This will store the Model View and Perspective Matrices and will convert them to Constant buffer safe Data 
 * 
 */
ModelViewProjectionManager::ModelViewProjectionManager()
{
}

/**
 * @brief Destroy the Model View Projection Manager:: Model View Projection Manager object
 * 
 */
ModelViewProjectionManager::~ModelViewProjectionManager()
{
}

/**
 * @brief store a matrix in 1 of the 3 types
 * 
 * @param type integer of representing matrix (0 = model, 1 = view, 3 = perspective)
 * @param mat the matrix to store
 */
void ModelViewProjectionManager::SetMatrix(UINT type, XMMATRIX mat)
{
	if (type == MATKEY_MODEL) {
		m_model = mat;
	}
	else if (type == MATKEY_VIEW) {
		m_view = mat;
	}
	else if (type == MATKEY_PROJECTION) {
		m_projection = mat;
	}
}

/**
 * @brief store a matrix in 1 of the 3 types
 * 
 * @param type integer of representing matrix to get (0 = model, 1 = view, 3 = perspective)
 */
XMMATRIX ModelViewProjectionManager::GetMatrix(UINT type)
{
	if (type == MATKEY_MODEL) {
		return m_model;
	}
	else if (type == MATKEY_VIEW) {
		return m_view;
	}
	else if (type == MATKEY_PROJECTION) {
		return m_projection;
	}
	return XMMATRIX{};
}

/**
 * @brief turns the Matrices into Constant buffer usable data.
 * 
 * @return Structures::ModelViewProjectionConstantBuffer 
 */
ModelViewProjectionConstantBuffer ModelViewProjectionManager::GetCbvData()
{
	ModelViewProjectionConstantBuffer value;

	XMStoreFloat4x4(&value.model, m_model);
	XMStoreFloat4x4(&value.view, m_view);
	XMStoreFloat4x4(&value.projection, m_projection);

	return value;
}
